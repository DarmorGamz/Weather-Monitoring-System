<?php
    // Includes
    require_once '/var/www/html/Private/Globals.php';

    $sData = file_get_contents('php://input'); // Get the POST request body

    // Split the input string into records
    $records = explode(';', $sData);

    // Parse each record for the values
    $sQry = "INSERT INTO WeatherData (DataType, Value, DateMsUtc) VALUES";
    foreach ($records as $record) {
        // Split the record into fields
        $fields = explode(',', $record);

        // Parse the fields for the values
        $iDataType = substr($fields[0], strpos($fields[0], ':') + 1);
        $value = substr($fields[1], strpos($fields[1], ':') + 1);
        $float = substr($fields[2], strpos($fields[2], ':') + 1);
        $iDateMsUtc = substr($fields[3], strpos($fields[3], ':') + 1);

        if($iDateMsUtc < 1680917868 || $iDateMsUtc > 2000000000) continue; // Stops garbage values.

        if(!isset($iDataType) || !isset($value) || !isset($float) || empty($iDateMsUtc)) continue; // Stops garbage values.

        $combined = $value . '.' . $float;
        $iValue = floatval($combined);

        // Create Temp Row.
        $sTempRowInsert = " ({$iDataType}, {$iValue}, {$iDateMsUtc}),";

        // Append Row.
        $sQry = $sQry.$sTempRowInsert;
    }
    $sQry = substr_replace($sQry, ";", -1);

    // Init object
    if(!$oDb = mysqli_connect(DB_HOST, DB_USER, DB_USER_PWD, "Data")) {  }

    if(($oRes = $oDb->query($sQry)) === false) { }

    // DeInit object.
    $oDb->close();

    // Set the response body
    $response_body = time();

    // Calculate the content length
    $content_length = strlen($response_body);

    // Set the HTTP response code to 200 OK
    http_response_code(200);

    // Set the content type to plain text
    header('Content-Type: text/plain');

    // Set the Content-Length header
    header('Content-Length: ' . $content_length);

    // Return the response body
    echo $response_body;