import cv2
import cvzone
import serial
from cvzone.HandTrackingModule import HandDetector
from cvzone.SerialModule import SerialObject


cap = cv2.VideoCapture(0)
detector = HandDetector(maxHands=1, detectionCon=0.7)
Arduino_Serial = serial.Serial('COM4',9600)  
# s = Arduino_Serial.readline()
# Arduino_Serial.close()

while True:
    success, img = cap.read()
    img = detector.findHands(img)
    lmList, bbox = detector.findPosition(img)
    if lmList:
        # Arduino_Serial.open()
        fingers = detector.fingersUp()
        print(fingers)
        if fingers[0]==fingers[1]==fingers[2]==fingers[3]==fingers[4]==0:
            print('0')
            Arduino_Serial.write('0'.encode()) 
        else:
            print('1')
            Arduino_Serial.write('1'.encode()) 
        # mySerial.sendData(fingers)
        
        # Arduino_Serial.close()
    cv2.imshow("Image",img)
    cv2.waitKey(1)


    
