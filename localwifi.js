var net = require('net');
var os = require('os');
var child = require('child_process');
var exec = require('child_process').exec;

var interfaces = os.networkInterfaces();
var myIp = interfaces.en0[1].address;

child = exec("arp -a", function (error, stdout, stderr) {
  // sys.print('\nstdout: ' + stdout);
  // sys.print('\nstderr: ' + stderr);
  var inet4Addresses = stdout.match(/\([^)]+\)/g);
  console.log('\n ------- \n', inet4Addresses, '\n ------ \n');
  console.log(inet4Addresses.length, '\n ------ \n');
    if (error !== null) {
    console.log('exec error: ' + error);
  }
});

// console.log(myIp);
// console.log(interfaces);
// console.log(path);
// console.log(process);
// console.log(url.Url('127.0.0.1'));
// console.log(environment);
// console.log(user);
