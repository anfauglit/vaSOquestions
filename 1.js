let arr = ['cafe', 'fruit', 'legumes']

let objs = [
	{name: 'cafe'},
	{name: 'fruit'}
]

let result = arr.filter(x => {flag = true; objs.forEach(y => {if (x === y.name) flag = false;}); return flag});
// but then I've discovered that there is array method .every
console.log(result)

/*
expected result = ['legumes']
*/
