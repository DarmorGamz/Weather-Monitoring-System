// Define the data to be sent in the POST request
const dataWeather = {
    Cmd: "getdata",
    DataType: "10",
};

const paramsWeather = new URLSearchParams();
paramsWeather.append('Cmd', dataWeather.Cmd);
paramsWeather.append('DataType', dataWeather.DataType);

// Set the URL of the server you want to send the POST request to
const urlWeather = 'https://darmorgamz.ca/api.php?' + paramsWeather.toString();

// Define the function to send the POST request
function sendPostRequestWeather() {
    fetch(urlWeather, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
    })
        .then(response => response.json())
        .then(json => {
            const weatherData = json.Weather;

            document.getElementById('weather-icon').src = weatherData.current.condition.icon;
            document.getElementById('weather-humidity').textContent = weatherData.current.humidity;
            document.getElementById('weather-wind-speed').textContent = weatherData.current.wind_kph;
            document.getElementById('weather-wind-dir').textContent = weatherData.current.wind_dir;
            document.getElementById('weather-precip').textContent = weatherData.current.precip_mm;
            document.getElementById('weather-feelslike').textContent = weatherData.current.feelslike_c;
            document.getElementById('weather-cloud').textContent = weatherData.current.cloud;
        })

        .catch(error => console.error(error));
}

sendPostRequestWeather();

// Send the POST request every minute using setInterval()
const intervalWeather = setInterval(sendPostRequestWeather, 60000); // 60000 ms = 1 minute