import RPi.GPIO as GPIO
import time
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(11, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)         #Read output from PIR motion sensor
GPIO.setup(21, GPIO.OUT, initial=GPIO.LOW)         #SSR Switch Pin
while True:
	i=GPIO.input(11)
	if i==0:                 #When output from motion sensor is LOW
		print "No intruders",i
		GPIO.output(21, 0)  #Turn OFF Lights
		time.sleep(1)		#Sleep 1 Second (we don't need it to super accurate)
	elif i==1:               #When output from motion sensor is HIGH
		print "Intruder detected",i
		time.sleep(0.7) #wait for continued detection
		i=GPIO.input(11)
		if i==1:
			GPIO.output(21, 1)  #Turn ON Lights
			time.sleep(60)		# Sleep 1 min. We want the light to stay on for 1 min.
								# if we don't do this the pir sensor can overide the on state.
		else:
			GPIO.output(21,0)
			time.sleep(1)
			
# GPIO.add_event_detect(11, GPIO.RISING)
# def my_callback():
	# #print 'PUSHED!'
	# GPIO.output(21, GPIO.input(11))  #Turn ON Lights
# GPIO.add_event_callback(11, my_callback)