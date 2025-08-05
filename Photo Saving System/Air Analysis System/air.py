import pyautogui
import time

def capture_screenshots(num_screenshots):
    for i in range(1, num_screenshots + 1):
        time.sleep(5)
        screenshot = pyautogui.screenshot()
        screenshot.save(f"air{i}.png")

capture_screenshots(1)
