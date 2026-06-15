from arduino.app_utils import *
from arduino.app_bricks.web_ui import WebUI

# Global state
led_is_on = False
LED1_R = "/sys/class/leds/unoq:user-red1/brightness"

def get_led_status():
    """Get current LED status for API."""
    return {
        "led_is_on": led_is_on,
        "status_text": "LED IS ON" if led_is_on else "LED IS OFF"
    }

def toggle_led_state(client, data):
    """Toggle the LED state when receiving socket message."""
    global led_is_on
    led_is_on = not led_is_on

    Bridge.call("set_led_state", led_is_on)

    ui.send_message('led_status_update', get_led_status())

def on_get_initial_state(client, data):
    """Handle client request for initial LED state."""
    ui.send_message('led_status_update', get_led_status(), client)

def toggle(state):
    try:
        with open(LED1_R, "w") as f:
            f.write(f"{value}\n")
    except Exception as e:
        print(f"Error: {e}")

# Initialize WebUI
ui = WebUI()

ui.on_message('toggle_led', toggle_led_state)
ui.on_message('get_initial_state', on_get_initial_state)

# Toggle MPU LED from Arduino IDE Serial Monitor
Bridge.provide("toggle", toggle);

App.run()
