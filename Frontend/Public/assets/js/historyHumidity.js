// Define the date
var d = new Date();
var date = d.toISOString().slice(0,10);

// Define the data to be sent in the POST request
const dataWeatherHist = {
    Cmd: "getdata",
    DataType: "11",
    Date: date,
};

const paramsWeatherHist = new URLSearchParams();
paramsWeatherHist.append('Cmd', dataWeatherHist.Cmd);
paramsWeatherHist.append('DataType', dataWeatherHist.DataType);
paramsWeatherHist.append('Date', dataWeatherHist.Date);

// Set the URL of the server you want to send the POST request to
const urlWeatherHist = 'https://darmorgamz.ca/api.php?' + paramsWeatherHist.toString();

// Define the function to send the POST request
function sendPostRequestWeatherHist() {
    fetch(urlWeatherHist, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
    })
        .then(response => response.json())
        .then(json => {
            const weatherData = json.Weather;

            document.getElementById('humidity-lastyear').textContent = weatherData.forecast.forecastday[0].hour[d.getHours()].humidity;
        })

        .catch(error => console.error(error));
}

sendPostRequestWeatherHist();

// Send the POST request every minute using setInterval()
const intervalWeatherHist = setInterval(sendPostRequestWeatherHist, 60000); // 60000 ms = 1 minute