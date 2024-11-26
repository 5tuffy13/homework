import requests
import webbrowser
url = "https://api.nasa.gov/planetary/apod?api_key=mCwakTe9AhrNaBP3AWAq80C8f7IQVDnY8membmuk"
respond = requests.get(url)
data = respond.json()
title = data['title']
description = data['explanation']
image = data['hdurl']
print(f'Title: {title}\n\n\nDescription:\n\n{description}\n\n\nLink: {image}')
webbrowser.open(image)
