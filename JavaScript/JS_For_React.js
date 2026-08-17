// Destructuring-> unpack values from objects in variables.
const user={
    name: "Akhil",
    age:21,
    Branch:"ENC"
}
const {name, age, Branch:userBranch}=user;
console.log(age);
console.log(userBranch);

const{name:username, ...rest}=user // agar yahan kalla name likhunga toh invalid hojega as upar const name hai
console.log(rest);

// Spread operator
const array=[1,2,3]
const newArray=array
newArray.push(4)
console.log(array);
console.log(newArray); // 4 gets pushed in the orignal one as well.

const spreadArray=[...array,5];
console.log(array);
console.log(spreadArray); // now it stays in the copy itself.

const newuser={...user, RollNo:3}
console.log(newuser)

// export default function DoSomething(){

// }

// functions with const
export const DoSomething=()=>{}

// Map and filter

let names=["Akhil", "Divyam", "Ritvik", "Abhinav"];

console.log("\nMap: ");
names.map((name)=>{
    console.log(name)
})

console.log("\nFilter: ");
names.filter((name)=>{
    if(name!="Divyam")
        console.log(name);
})
