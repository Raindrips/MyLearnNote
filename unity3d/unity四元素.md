##  四元素Quaternion

```c#
//1.先绕Z轴转动90度，再绕X轴转动30度，最后绕Y轴转动60度
Quaternion rot=Quaternion.Euler(30,60,90);

//绕自身正方向转60度
Quaternion rot= Quaternion.AngleAxis(60, transform.forward);

//相乘
Quaternion rot1=Quaternion.Euler(0,30,0);
Quaternion rot2=Quaternion.Euler(0,0,45);
//先执行rot2旋转,然后执行rot1旋转
Quaternion rot=rot2*rot1;		

//to是将Vector3.forward绕Vector3.up旋转45度后得到的新向量
//与向量向乘
Vector3 to = Quaternion.AngleAxis(45, Vector3.up)*Vector3.forward;

//已知两个向量，求从一个向量转到另一个向量的四元数：
//这的意思是创建一个从y轴正方向到z轴正方向的旋转角度所对应的四元数
Quaternion rot=Quaternion.FromToRotation(Vector3.up，Vector3.forward);

//这的意思是此游戏对象自身转向这个计算出来的偏转角所对应的四元数，如果将此至于Update中就可以做到不断对准目标
Vector3 aimDirection=(targetTrans.position – transform.position).normalized;
Quaternion rot = Quaternion.FromToRotation(transform.up,aimDirection);
transform.rotation = rot * transform.rotation;

//创建一个让Z轴正方向和Y轴正方向指向规定方向的旋转  
Quaternion rot = Quaternion.LookRotation(Vector3.right, Vector3.down);
```

## 