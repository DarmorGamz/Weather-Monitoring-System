
// Temp: 0,
// Hum: 1,

//Define js object
var TemperaturePoints = [];

// Define the data to be sent in the POST request
const dataTemp = {
    Cmd: "getdata",
    DataType: "0",
};

const params = new URLSearchParams();
params.append('Cmd', dataTemp.Cmd);
params.append('DataType', dataTemp.DataType);

// Set the URL of the server you want to send the POST request to
const url = 'https://darmorgamz.ca/api.php?' + params.toString();

// Define the function to send the POST request
function sendPostRequest() {
    fetch(url, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
    })
        .then(response => response.json())
        .then(json => {
            const data = json.Data;
            TemperaturePoints = data.Temperature;

        })
        .catch(error => console.error(error));
}

// Send the POST request every minute using setInterval()
const interval = setInterval(sendPostRequest, 1000); // 60000 ms = 1 minute


function highchartSetup() {
    var currentTime = (new Date()).getTime();
    var minTime = currentTime-(15*60*1000); // 15 minutes ago
    var maxTime = currentTime; // current time

    // Set up the chart
    var chart = Highcharts.chart('chart-container', {
        chart: {
            type: 'line',
            zoomType: 'x', // Enable zooming on both axes
            events: {
                load: function () {
                    this.isZoomed = false;
                    // set up the updating of the chart every 1 second
                    var series = this.series[0];
                    var xAxis = this.xAxis[0];
                    setInterval(function () {
                        if (!chart.isZoomed) {
                            series.setData(TemperaturePoints);
                            var currentTime = (new Date()).getTime();
                            var minTime = currentTime-(15*60*1000); // 15 minutes ago
                            var maxTime = currentTime; // current time
                            xAxis.setExtremes(minTime, maxTime);
                        }
                    }, 1000);
                },
                selection: function (event) {
                    if (event.resetSelection) {
                        this.isZoomed = false;

                        var series = this.series[0];
                        var xAxis = this.xAxis[0];
                        series.setData(TemperaturePoints);
                        var currentTime = (new Date()).getTime();
                        var minTime = currentTime-(15*60*1000); // 15 minutes ago
                        var maxTime = currentTime; // current time
                        xAxis.setExtremes(minTime, maxTime);
                    } else {
                        this.isZoomed = true;
                    }
                }
            }
        },
        resetZoomButton: {
            theme: {
                display: 'block' // Show the reset zoom button
            }
        },
        title: {
            text: 'Temperature'
        },
        xAxis: {
            title: {
                text: 'Time'
            },
            type: 'datetime',
            tickPixelInterval: 150,
            min: minTime,
            max: maxTime,
            tickInterval: 2 * 60 * 1000 // 2 minutes
        },
        yAxis: {
            title: {
                text: 'Celsius'
            },
            labels: {
                format: '{value:.2f}'
            },
            plotLines: [{
                value: 0,
                width: 1,
                color: '#663399'
            }]
        },
        tooltip: {
            formatter: function () {
                return '<b>' + this.series.name + '</b><br/>' +
                    Highcharts.dateFormat('%Y-%m-%d %H:%M:%S', this.x) + '<br/>' +
                    Highcharts.numberFormat(this.y, 2);
            }
        },
        legend: {
            enabled: false
        },
        exporting: {
            enabled: false
        },
        series: [{
            name: 'Temperature Data',
            data: TemperaturePoints
        }]
    });
}