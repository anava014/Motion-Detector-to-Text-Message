<?php 
        if(isset($_GET['trigger']) && $_GET['trigger'] == 1) {
            //body.sh is a short script that prints an alert message
            //and a timestamp
            exec('./body.sh | mail -s "ALERT" phoneNumber@messaging.sprintpcs.com');
			exec('./body.sh | mail -s "ALERT" phoneNumber@messaging.sprintpcs.com');
			exec('./body.sh | mail -s "ALERT" phoneNumber@vtext.com');
			exec('./body.sh | mail -s "ALERT" phoneNumber@txt.att.net');
        }
?>
