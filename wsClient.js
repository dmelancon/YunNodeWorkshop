var WebSocket = require('ws')
  , ws = new WebSocket('ws://104.131.39.242:3000/');

ws.on('open', function() {
    ws.send('Arduino Here!');
});

// READLINE PORTION

var readline = require('readline'); // include the readline module
 
console.log("Hello Arduino");       // send an intial message on startup
    
// create an interface to read lines from the Arduino:
var lineReader = readline.createInterface({
  input: process.stdin,	
  output: process.stdout,
  terminal: false
});
 
// when you get a newline in the stdin (ends with \n),
// send a reply out the stdout:
lineReader.on('line', function (data) {
	ws.send(data);
	console.log('You sent: '+ data);
});