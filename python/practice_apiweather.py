import requests
city = input('Type a city name\n')
url = f"http://api.openweathermap.org/data/2.5/weather?q={city}&amp&units=metric&appid=94f84006b07c41b7ab86c397ab45ac65"
response = requests.get(url)
temp = response.json()["main"]["temp"]
weather = response.json()["weather"][0]["main"]
wind = response.json()["wind"]["speed"]
print(f"Temperature: {temp}(C)\nWeather: {weather} \nWind speed: {wind}(mps)")
