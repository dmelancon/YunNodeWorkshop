//===========================================================
//=================== HTTP PORTION ==========================
//===========================================================

var http = require('http');
var fs = require('fs'); // Using the filesystem module
var httpServer = http.createServer(requestHandler);
var url = require('url');
httpServer.listen(4000);

console.log("Listening on 4000");

function requestHandler(req, res) {

	var parsedUrl = url.parse(req.url);
	console.log("The Request is: " + parsedUrl.pathname);
	
	// Read index.html
	
	fs.readFile(__dirname + parsedUrl.pathname, 
		// Callback function for reading
		function (err, data) {
			// if there is an error
			if (err) {
				res.writeHead(500);
				return res.end('Error loading ' + parsedUrl.pathname);
			}
			// Otherwise, send the data, the contents of the file
			res.writeHead(200);
			res.end(data);
  		}
  	);
}

//========================================================
//=============== SOCKET.IO PORTION ======================
//========================================================

var io = require('socket.io').listen(httpServer);

var connectedSockets = [];

var countDownActive = false;

io.sockets.on('connection', function (socket){

	console.log("We have a new client: " + socket.id);

	//add it to the array of connected sockets
	connectedSockets.push(socket);

});

//===========================================================
//======================= WS Server =========================
//===========================================================

var WebSocketServer = require('ws').Server
  , wss = new WebSocketServer({port: 3000});

var wsMessage;

console.log("Listening on 3000");

wss.on('connection', function(ws) {

	console.log("New Connection!");

    ws.on('message', function(message) {
        console.log('From Arduino: %s', message);
        // wsMessage = message;
        io.sockets.emit('deltaEvent', message);
    });
});

