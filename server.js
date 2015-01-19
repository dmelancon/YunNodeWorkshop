var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var WebSocket = require('ws')
  , ws = new WebSocket('ws://192.168.1.13:3000/');

ws.on('error', function(){
  console.log("Yun WS Server not found");
});

app.get('/', function(req, res){
  res.sendFile(__dirname + '/test.html');
});

io.on('connection', function(socket){
  socket.on('message', function(msg){
    msg = msg.replace(/(<([^>]+)>)/ig,"");
    io.emit('message', msg);
    msg = msg.replace(/&nbsp;/g,'');
    ws.send(msg+"\n",function ack(error){});
    console.log(msg);
  });
});

http.listen(8000, function(){
  console.log('listening on *:8000');
});