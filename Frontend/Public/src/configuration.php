<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>A+ - Config</title>

    <link rel="stylesheet" type="text/css" href="../assets/css/navbar.css">
    <link rel="stylesheet" type="text/css" href="../assets/css/hamburgermenu.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/css/all.min.css" crossorigin="anonymous">
    <link rel="icon" type="image/x-icon" href="../assets/img/favicon.ico">

    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="../assets/js/sessionkeycheck.js"></script>
    <script src="../assets/js/configuration.js"></script>

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
            <a href="homepage.php#Temperature"><li><i class="fas fa-temperature-high menuicons"></i>Temperature</li></a>
            <a href="humidity.php#Humidity"><li><i class="fas fa-temperature-low menuicons"></i>Humidity</li></a>
            <a href="pressure.php#Pressure"><li><i class="fas fa-thermometer menuicons"></i>Pressure</li></a>
            <a href="#"><li><i class="fas fa-bug menuicons"></i>N/A</li></a>
            <a href="#"><li><i class="fas fa-bug menuicons"></i>N/A</li></a>
            <a href="#"><li><i class="fas fa-bug menuicons"></i>N/A</li></a>
            <a href="#"><li><i class="fas fa-bug menuicons"></i>N/A</li></a>
            <a href="#"><li><i class="fas fa-bug menuicons"></i>N/A</li></a>
            <a href="#"><li><i class="fas fa-bug menuicons"></i>N/A</li></a>
            <a href="configuration.php#Configuration"><li><i class="fas fa-cog menuicons"></i>Configuration</li></a>
            <a href="about.php#About"><li><i class="fas fa-graduation-cap menuicons"></i>About</li></a>
            <a href="support.php#Support"><li><i class="fas fa-question-circle menuicons"></i>Support</li></a>
        </ul>
    </div>

    <!-- Content -->
    <div id="content" class="content">
        <h1>Configuration</h1>
        <div class="profile-container">
            <div class="profile-picture">
                <img src="../assets/img/Avatar1.jpg" alt="Profile Picture" class="profile-image">
            </div>
            <div class="user-info-container">
                <div class="user-info">
                    <div class="user-info-info">
                        <label>First Name:</label>
                        <input type="text" id="firstname" name="firstname" value="John" readonly>
                    </div>
                    <div class="user-info-info">
                        <label>Last Name:</label>
                        <input type="text" id="lastname" name="lastname" value="Doe" readonly>
                    </div>
                </div>
                <div class="user-info">
                    <div class="user-info-info">
                        <label>Email:</label>
                        <input type="text" id="email" name="email" value="john.doe@example.com" readonly>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <!-- Footer -->
    <footer class="footer">
        <span>&copy; 2023 A+ Interface</span>
    </footer>
</body>
</html>
