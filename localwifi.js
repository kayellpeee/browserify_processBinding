var os = require('./lib/os.js');
var child = require('./lib/child_process.js');
// var child = require('child_process');

var interfaces = os.networkInterfaces();
var myIp = interfaces.en0[1].address;
var exec = child.exec;
var spawn = child.spawn;

var arp = exec("arp -a", function (error, stdout, stderr) {
  // sys.print('\nstdout: ' + stdout);
  // sys.print('\nstderr: ' + stderr);
  var inet4Addresses = stdout.match(/\([^)]+\)/g);
  console.log('\n ------- \n', inet4Addresses, '\n -----');
  inet4Addresses.forEach(function(address){
    var newItem = document.createElement('li');
    var newText = document.createTextNode(address);
    newItem.appendChild(newText);
    document.getElementsByTagName('li')[0].appendChild(newItem);
  });
  alert(myIp);
  // console.log('localhost: ', myIp);
  // console.log(inet4Addresses.length);
    // if (error !== null) {
    // console.log('exec error: ' + error);
  // }
});
