 

# UI控件

## BaseAdapt

```java
class BaseAdapt{
	int getConunt()		//适配器中收集数据的个数
	
	Object getItem(int position);		//获取数据中索引对应数据项
	
	long getItemID(int position);   //获取数据中索引对应ID
	
	View getView(int position,View convertView,ViewGroup parent); //获取每个Item的显示内容

}
```

## fagmemt

```java
fragment
onAttach() --用于fragment的参数传递
onCreate() --fragment的开始创建
onCreateView() --创建要加载的View
onActivityCreated() --Activity加载完成
onStart()
onResume()
onPause()
onStop()
onDetach() --fragment生命周期的一个回调方法
```

