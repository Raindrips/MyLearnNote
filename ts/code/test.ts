//数据结构
//  基本数据类型
let a;              //定义了一个变量a
let a1: number;     //定义了一个数字类型的变量a1
let a2: string;      //字符串类型

a2 = 'hello world';
let a3: boolean;     //true false
a3 = true;
a3 = false;
let arr: Array<number> = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let arr2: Array<string> = ['a', 'b', 'c', 'd', 'e'];

let obj = {
    a: 10,
    b: true,
    c: 'string'
};
//算法
//分支语句
if (10 > 5) {
    //console.log  cocos creator 的打印输出语句
    console.log('真');
}
else {
    console.log('假');
}
//开关语句的使用
let w = 0;
switch (w) {
    case 1:
        console.log('执行语句1');
        break;
    case 2:
        console.log('执行语句2');
        break;
    case 3:
        console.log('执行语句3');
        break;
    default:
        console.log('没有这个选项');
}

//循环语句