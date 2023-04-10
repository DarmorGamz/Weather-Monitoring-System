<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>A+ - About</title>

    <link rel="stylesheet" type="text/css" href="../assets/css/navbar.css">
    <link rel="stylesheet" type="text/css" href="../assets/css/hamburgermenu.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/css/all.min.css" crossorigin="anonymous">
    <link rel="icon" type="image/x-icon" href="../assets/img/favicon.ico">

    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="../assets/js/sessionkeycheck.js"></script>

    <script>
        document.addEventListener("DOMContentLoaded", function() {
            // Get the menu toggle button and the menu container
            const menuToggle = document.getElementById('menu-toggle');
            const menuContainer = document.getElementById('menu-container');
            const contentContainer = document.getElementById('content');

            // Opens menu on default
            menuContainer.classList.add('active');
            contentContainer.classList.add('menu-open');

            // Add a click event listener to the menu toggle button
            menuToggle.addEventListener('click', function() {
                // Toggle the 'active' class on the menu container to open/close it
                menuContainer.classList.toggle('active');

                // Add/remove the 'menu-open' class to the content container to adjust the margin left
                contentContainer.classList.toggle('menu-open');
            });
        });
    </script>
</head>
<body>
    <!-- Navbar -->
    <nav class="navbar sticky">
        <!-- Hamburger menu icon -->
        <button id="menu-toggle" class="menu-toggle">
            <i class="fas fa-bars"></i>
        </button>
        <!-- Logo -->
        <div class="logo-container">
            <img src="../assets/img/logo.png" alt="Logo">
        </div>
        <!-- Login button -->
        <div class="login-button">
            <span id="UserEmail"></span>
            <span class="tooltip" data-tooltip="Logout">
                        <button id="login-button"><i class="fas fa-lock"></i></button>
                        <div class="tooltip-text">Logout</div>
                    </span>
            <span class="tooltip" data-tooltip="Support">
                        <button id="Support-button"><i class="fas fa-question-circle"></i></button>
                        <div class="tooltip-text">Support</div>
                    </span>
        </div>
    </nav>

    <!-- Menu -->
    <div id="menu-container" class="menu-container">
        <ul class="menu">
            <li><i class="fas fa-temperature-high menuicons"></i><a href="homepage.php#Temperature">Temperature</a></li>
            <li><i class="fas fa-temperature-low menuicons"></i><a href="humidity.php#Humidity">Humidity</a></li>
            <li><i class="fas fa-thermometer menuicons"></i><a href="pressure.php#Pressure">Pressure</a></li>
            <li><i class="fas fa-cog menuicons"></i><a href="configuration.php#Configuration">Configuration</a></li>
            <li><i class="fas fa-graduation-cap menuicons"></i><a href="about.php#About">About</a></li>
            <li><i class="fas fa-question-circle menuicons"></i><a href="support.php#Support">Support</a></li>
        </ul>
    </div>

    <!-- Content -->
    <div id="content" class="content">
        <h1>About</h1>
        <p class="section-text">
            IoT Weather Monitoring is a state-of-the-art system designed to collect real-time data on temperature, pressure, and humidity. Leveraging the power of the Stm32 B-L475E Devboard, our IoT device records and sends accurate readings to our secure AWS server, where the data is then stored in an RDS database for further analysis.
        </p>
        <h3 class="section-title">Key Features</h3>
        <ul class="section-text">
            <li><span class="highlight">Real-time data collection:</span> Accurate temperature, pressure, and humidity readings are collected by the IoT device, giving users up-to-date information on their local environment.</li>
            <li><span class="highlight">AWS Integration:</span> Our robust AWS infrastructure ensures data reliability and security, with servers hosted on AWS EC2 and data storage on RDS databases.</li>
            <li><span class="highlight">Responsive API:</span> Our PHP backend provides an intuitive and efficient API for frontend users, ensuring a seamless experience.</li>
            <li><span class="highlight">WeatherAPI.com Integration:</span> Incorporating real-time weather data from WeatherAPI.com allows for data comparisons and improved decision-making for users.</li>
        </ul>

        <!-- Technologies Used -->
        <h2 class="section-title">Technologies Used</h2>
        <div class="section-text tech-items-container">
            <div class="tech-item">
                <img src="../assets/img/stmicroelectronics.svg" alt="Stm32" class="tech-logo">
                <div class="tech-label">Stm32</div>
            </div>
            <div class="tech-item">
                <img src="../assets/img/amazonaws.svg" alt="AWS" class="tech-logo">
                <div class="tech-label">AWS</div>
            </div>
            <div class="tech-item">
                <img src="../assets/img/amazonec2.svg" alt="EC2" class="tech-logo">
                <div class="tech-label">Amazon EC2</div>
            </div>
            <div class="tech-item">
                <img src="../assets/img/amazonrds.svg" alt="RDS" class="tech-logo">
                <div class="tech-label">Amazon RDS</div>
            </div>
            <div class="tech-item">
                <img src="../assets/img/php.svg" alt="PHP" class="tech-logo">
                <div class="tech-label">PHP</div>
            </div>
            <div class="tech-item">
                <img src="../assets/img/mysql.svg" alt="MySQL" class="tech-logo">
                <div class="tech-label">MySQL</div>
            </div>
            <div class="tech-item">
                <img src="../assets/img/javascript.svg" alt="JavaScript" class="tech-logo">
                <div class="tech-label">JavaScript</div>
            </div>
            <div class="tech-item">
                <img src="../assets/img/html5.svg" alt="HTML5" class="tech-logo">
                <div class="tech-label">HTML5</div>
            </div>
            <div class="tech-item">
                <img src="../assets/img/css3.svg" alt="CSS3" class="tech-logo">
                <div class="tech-label">CSS3</div>
            </div>
            <div class="tech-item">
                <img src="../assets/img/c.svg" alt="C" class="tech-logo">
                <div class="tech-label">C</div>
            </div>
        </div>

        <h3 class="section-title">Get Started</h3>
        <p class="section-text">
            To start using IoT Weather Monitoring and experience the benefits of real-time environmental data, simply register for an account and follow the setup instructions. Our user-friendly interface makes it easy for you to access, analyze, and compare your collected data.
        </p>
        <p class="section-text">
            If you have any questions or need assistance, please don't hesitate to <a href="contact.html" class="highlight">contact us</a>. Our team is always happy to help.
        </p>
    </div>

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>

<!-- Footer -->
<footer class="footer">
    <span>&copy; 2023 A+ Interface</span>
</footer>
</body>
</html>
