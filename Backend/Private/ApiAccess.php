<?php

// Includes
require_once '/var/www/html/Private/Globals.php';

final class ApiAccess {
    // Methods
    private $aResp = [], $aIpVar = [];

    /**
     * Constructor.
     */
    final public function __construct() {
        // Init vars.
        $this->aResp['Errors'] = [];
        $this->aResp['DateMsUtc'] = time();
        $this->ProcCmd();
    }
    /**
     * Destructor.
     */
    final public function __destruct() {}

    final public function ProcCmd(): bool {
        // Get Post/Get vars.
        $aInput = $_POST; $aInput += $_GET;
        foreach($aInput as $key => $val) {
            $sKey = html_entity_decode(urldecode($key));
            if(!preg_match('/^[a-zA-Z0-9]+$/', $sKey)) continue;
            $sVal = html_entity_decode(urldecode($val));
            if(empty($sVal)) { //  && ($sVal != 0)
                $this->aIpVar[$sKey] = '';
            } else {
                if(!preg_match('/^[\x20-\x7E]+$/', $sVal)) continue;
                $this->aIpVar[$sKey] = $sVal;
            }
        }

        $sCmd = '';
        if(empty($this->aIpVar['Cmd'])) { return false; }
        $sCmd = $this->aIpVar['Cmd'];
        $this->aResp['Cmd'] = $sCmd;

        switch($sCmd) {
            default: // Not a valid endpoint.
                $this->SetError(1, "Cmd not found."); return false;
                break;
        }

        // Return Success.
        return true;
    }

    final private function SetError(int $iCode, string $errorMsg): void {
        $this->aResp['Errors'][] = [$iCode, $errorMsg];
    }

    final private function GetInputVar(string $IpVar, &$IpVarOut): bool {
        switch($IpVar) {
            case "Email":
                // Checks if Email is valid.
                if((!isset($this->aIpVar['Email'])) || (!filter_var($this->aIpVar['Email'], FILTER_VALIDATE_EMAIL)) || strlen($this->aIpVar['Email']) > 100) return false;
                // Returns the valid email.
                $IpVarOut = $this->aIpVar['Email'];
                break;
            case "Password":
                // Checks if Email is valid.
                if(!isset($this->aIpVar['Password']) || empty($this->aIpVar['Password']) || strlen($this->aIpVar['Password']) > 25) return false;
                // Returns the valid email.
                $IpVarOut = $this->aIpVar['Password'];
                break;
            default:
                return false;
                break;
        }
        // Return Success.
        return true;
    }

    final public function SendResponse(): bool {
        // JSON encode array
        $sResp = json_encode($this->aResp);
        // Add text/plain header so receiving application knows the type of data
        header('Content-Type: application/json');

        // Return response
        echo($sResp);

        // Return success.
        return true;
    }

}