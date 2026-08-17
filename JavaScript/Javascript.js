let number=3; // block scoped, can be overwritten.
console.log("My Number: " + number);

const num=3 // block scoped, can't be overwritten.
// num=4
// console.log(num)  This is an error. Const keyword is used when we dont want a variables values overwritten.
// let is used when they can be overwritten.

if(num==3){
    var ageee=3;
}
console.log(ageee); // this will run as var is function scoped and can be overwritten.


// == is normal equality
// === is strict equality. it checks dataypes as well.


let age=20;
if(age>18){
    console.log("Adult");
}
else {console.log("Not Adult");}

let count=1;
while(count<=10){
    console.log(count);
    count++;
}


// functions
function Hello(){
    console.log("Hello");
}
Hello(); // javascript doesn't support function overloading.

function Hello(username){
    console.log("Hello " + username);
}
Hello("Akhil");


// arrays
let users=["Akhil", "Divyam", "Abhinav"];
function signup(username){
    users.push(username);
    //users.pop(); to remove last element.
    console.log("Final users list: "+ users);
}
signup("Navya");


// for each method
console.log("\n FOR EACH METHOD: ");
users.forEach(printuser);

function printuser(name){
    console.log("For each: " + name);
}
// Arrow function
/* users.forEach((name)=>{
    console.log(name);   
   })
*/

// objects
console.log("\nObjects: ")
let obj={
    name: "Akhil",
    age:21,
    branch:"ENC"
}
console.log(obj);
console.log(obj.name);


// array of objects
let arrobj=[
    {name: "Akhil", age:21, branch:"ENC"},
    {name: "Divyam", age:21, branch:"COE"},
    {name: "Navya", age:21, branch:"COE"},
]
console.log(arrobj[2].name);