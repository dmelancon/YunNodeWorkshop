//===========================================================
//======================= WS Server =========================
//===========================================================

var WebSocketServer = require('ws').Server
  , wss = new WebSocketServer({port: 3000});

var theMessage = "";

console.log("Listening on 3000");

wss.on('connection', function(ws) {

	console.log("New Connection!");

    ws.on('message', function(message) {
        theMessage = message;
        console.log(theMessage);
    });

    ws.on('close', function() {
        console.log('Client disconnected.');
    });

    ws.on('error', function() {
        console.log('ERROR occured!');
    });

});

