import cv2
import cvzone
import serial
from cvzone.HandTrackingModule import HandDetector
from cvzone.SerialModule import SerialObject


cap = cv2.VideoCapture(0)
detector = HandDetector(maxHands=1, detectionCon=0.7)
Arduino_Serial = serial.Serial('COM3',9600)  
# s = Arduino_Serial.readline()
# Arduino_Serial.close()

while True:
    success, img = cap.read()
    img = detector.findHands(img)
    lmList, bbox = detector.findPosition(img)
    if lmList:
        # Arduino_Serial.open()
        fingers = detector.fingersUp()
        if fingers[0]:
            transfer='1'
        else:
            transfer='6'
        print(transfer)
        Arduino_Serial.write(transfer.encode()) 
        if fingers[1]:
            transfer='2'
        else:
            transfer='7'
        print(transfer)
        Arduino_Serial.write(transfer.encode()) 
        if fingers[2]:
            transfer='3'
        else:
            transfer='8'
        print(transfer)
        Arduino_Serial.write(transfer.encode()) 
        if fingers[3]:
            transfer='4'
        else:
            transfer='9'
        print(transfer)
        Arduino_Serial.write(transfer.encode()) 
        if fingers[4]:
            transfer='5'
        else:
            transfer='0'
        print(transfer)
        Arduino_Serial.write(transfer.encode()) 
        # if fingers[0]==fingers[1]==fingers[2]==fingers[3]==fingers[4]==0:
        #     print('0')
        #     Arduino_Serial.write(transfer.encode()) 
        # else:
        #     print('1')
        #     Arduino_Serial.write(transfer.encode()) 
        # mySerial.sendData(fingers)
        
        # Arduino_Serial.close()
    cv2.imshow("Image",img)
    cv2.waitKey(1)


    
