const fs = require('fs');

function zip(arrays) {
    return arrays[0].map(function(_,i){
        return arrays.map(function(array){return array[i]})
    });
}

// part 1
in1 = fs.readFileSync('input/day1.txt').toString().split('\r\n').map(function(item) {
    return parseInt(item);
});
in2 = fs.readFileSync('input/day1.txt').toString().split('\r\n').map(function(item) {
    return parseInt(item);
});
in2.splice(0, 1);
sol1 = zip([in1, in2]).filter(a => {
	return a[0] < a[1];
});

// second part
in2.splice(0, 2);
sol2 = zip([in1, in2]).filter(a => {
	return a[0] < a[1];
})

console.log(sol1.length, sol2.length);