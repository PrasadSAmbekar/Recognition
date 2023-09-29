import face_recognition
import cv2
import numpy as np
import csv
import os
from datetime import datetime

video_capture = cv2.VideoCapture(0)

steve_image =  face_recognition.load_image_file("photos/steve.jpg")
steve_encoding = face_recognition.face_encoding(steve_image)[0]

cr_image =  face_recognition.load_image_file("photos/cr.jpg")
cr_encoding = face_recognition.face_encoding(cr_image)[0]

Sundar_image =  face_recognition.load_image_file("photos/Sundar.jpg")
Sundar_encoding = face_recognition.face_encoding(Sundar_image)[0]

mark_image =  face_recognition.load_image_file("photos/mark.jpg")
mark_encoding = face_recognition.face_encoding(mark_image)[0]

known_faces_name = [
steve_encoding,
cr_encoding,
Sundar_encoding,
mark_encoding
]

known_faces_names = [
"Steve Jobs",
"GOAT",
"Sunadar Pichai",
"Mark "
]

students = known_faces_names.copy()

face_location = []
face_encoding = []
face_names = []
s = True

now = datetime.now()
current_date = now.strftime("%Y-%m-%d")