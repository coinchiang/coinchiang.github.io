# 补码

## 模的概念

> **模**是指一个计量系统的计数范围。如时钟，它存在一个计量范围，即存在一个“模”。

时钟的计量范围是`0～11`，模=`12`。

表示n位的计算机计量范围是0 ~ 2^n -1 ，模=2^n 。

**模**实质上是计量器产生**溢出**的量，它的值在计量器上表示不出来，计量器上只能表示出模的余数。**任何有模的计量器，均可化减法为加法运算**。

例如：假设当前时针指向10点，而准确时间是6点，调整时间可有以下两种拨法：

一种是倒拨4小时，即：10-4=6

另一种是顺拨8小时：10+8=12+6=6

在以12模的系统中，**加8和减4效果是一样的，因此凡是减4运算，都可以用加8来代替**。

对**模**而言，8和4互为**补数**。实际上以12模的系统中，11和1，10和2，9和3，7和5，6和6都有这个特性。共同的特点是**两者相加等于模**。

## 补码和模的关系

> 把补数用到计算机对数的处理上，就是补码。

对于计算机，其概念和方法完全一样。n位计算机，设n=8， 所能表示的最大数`1111 1111`，若再加1为`1 0000 0000`(9位)，但因只有8位，最高位1自然丢失。又回到了`0000 0000`，所以8位二进制系统的模为2^8^。

 在这样的系统中减法问题也可以化成加法问题，只需把减数用相应的补数表示就可以了。减去一个正数等于加上一个绝对值相等的负数，于是我们有了负数：

```
0000 0000        0
0000 0001        1
0000 0010        1
0000 0011        2
... ...
0111 1111        127

1000 0000        -128
1000 0001        -127
1000 0010        -126
1000 0011        -125
... ...
1111 1111        -1
```
## 原码补码转换

- 正数的补码与原码相同

- 对负数a有：`a的补码 = a绝对值的原码取反 + 1`

例如：

`1111 1111` -127原码

`0111 1111` 127的原码

`1000 0000` 取反

`1000 0001` 加1

有趣的是：对`1000 0001`取反得到`0111 1110`，再加1得到`0111 1111`即127的源码。取反再加1的规则可以在-a（a是负数）的原码与a的补码之间不停转化(**这不是逆运算**)

这一切的背后都有着严谨的数学原理，不过我不理解。

#  位运算

- `>>`无符号右移，高位补 `0`
- `>>>`有符号右移，高位补符号位
- `<<`左移，低位补 `0`

```java
在不溢出的前提下
a >>> 3	= a / 2 / 2 / 2
a << 2 = a * 2 * 2 * 2
```

# 常量的进制

```java
// 整数 常量
System.out.println(10);
// 二进制常量 13
System.out.println(0b01101);
// 八进制 10
System.out.println(012);
// 十六进制 65535
System.out.println(0xFFFF);
```

# 命名规范

## 包

一般都是公司域名的反写

纯小写，用逗号隔开

```java
com.xanadu.array
```

## 接口

大驼峰，在前加`I`(interface)

```java
IStudent
IUserService
```

## 接口的实现类

大驼峰，在后加`Impl`(implement)

```java
StudentImpl
```

## 抽象类

大驼峰，前加`Abs`(abstract)

```java
AbsStudent
```

## 常量

全大写，`_`分隔

```java
MAX_VALUE
```

# 基本数据类型转换

> `byte` >> `short` >> `int` >> `long` >> `float` >> `double`
>
> `char` [0 - 65535]
>
> `boolean`类型不参与数据类型转换

## 自动类型转换

将取值范围小的数据保存到取值范围大的数据类型中的时候自动转换类型

```java
byte by1 = 20;
int i = by1; // 将byte类型的变量赋值给int类型的变量，自动类型转换
System.out.println(i);
```

## 强制类型转换

```java
//注意转换时机
int random = (int)(Math.random() * 100);
//不加括号的话random就只能是0了
```

## 表达式类型提升

表达式中的类型提升与计算顺序有关，不会一上来就把各变量、常量统统都转化为表达式中最高级的类型

## Tips

- `byte`,`short`和`char`转换，都需要强制类型转换,因为`char`取值范围特殊
- 当`byte`,`short`,`char`之间参与运算的时候，都会转换为`int`类型来计算

- 扩展的赋值运算符（`+=`、`*=`等）默认执行强制类型转换

# 字符串与基本数据类型转换

```java
byte b1 = Byte.parseInt("123");
short s1 = Short.parseShort("123");
int i1 = Integer.parseInt("123");
long l1 = Long.parseLong("123");
float f1 = Float.parseFloat("123.456");
double d1 = Double.parseDouble("123.456");
boolean b2 = Boolean.parseBoolean("true");
```
# 方法的重载

> 在一个类中可以定义有相同名称，但参数列表不同的多个方法，调用的时候回根据不同的参数列表类选择对应的方法。 

参数列表不同：**参数的个数，顺序，类型不同** 

重载的特点：

1. **发生在同一个类中**
2. 方法名称相同
3. 参数列表不同(类型、个数、顺序)
4. **和返回类型没有关系**
4. 和访问权限修饰符没有关系

# 数组

## 冒泡排序

```java
public static void bubbleSort(int[] array) {
    for (int i = 0; i < array.length - 1; i++) {
        boolean isOrdered = true;
        for (int j = 0; j < array.length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int t = array[j];
                array[j] = array[j + 1];
                array[j + 1] = array[j];
                isOrdered = false;
            }
        }
        if (isOrdered) {
            break;
        }
    }
}
```

## 选择排序

```java
public static void selectionSort(int[] array) {
    for (int i = 0; i < array.length - 1; i++) {
        for (int j = i + 1; j < array.length; j++) {
            if (array[i] > array[j]) {
                int t = array[i];
                array[i] = array[j];
                array[j] = t;
            }
        }
    }
}
```

## 效率对比

> `System.currentTimeMillis()`	返回值类型为`long`
>
> the difference, measured in milliseconds, betweenthe current time and midnight, January 1, 1970 UTC.

```java
public class Time {
	/**
	 * 对比冒泡和选择 排序的效率
	 * @param args
	 */
	public static void main(String[] args) {
		int[] array = new int[1000];
		
		long startTime = System.currentTimeMillis();
        for (int j = 0; j < 10000; j++) {
            for (int i = 0; i < array.length; i++) {
                array[i] = (int)(Math.random() * 1000 + 1);
            }
            //bubbleSort(array);
            selectionSort(array);
        }
		long endTime = System.currentTimeMillis();
		System.out.println(endTime - startTime);
	}
}
```

|                 | 1     | 2     |
| --------------- | ----- | ----- |
| `bubbleSort`    | 1802  | 2193  |
| `selectionSort` | 14643 | 14594 |

> `Arrays.sort()` 是一种比传统快速排序更快的快速排序

## 数组扩容

```java
public static int[] expandArray(int[] array, int input) {
	int[] arrayNew = new int[array.length + 1]; 
		
	for (int i = 0; i < array.length; i++) {
			arrayNew[i] = array[i];
	}
	arrayNew[array.length] = input;
	return arrayNew;
}
```

## 二分查找

*使用二分查找时，操作数组要先排好序*

```java
public static int binarySearch(int[] array, int num) {
    int min = 0;
    int max = array.length - 1;
    int mid = (max + min) / 2;
    int index = -1;
    while (max != min) {
        if (num > array[mid]) {
            min = mid + 1;
        } else if (num < array[mid]) {
            max = mid - 1;
        } else {
            index = mid;
            break;
        }
        mid = (max + min) / 2;
    }
    if (index == -1) {
        index = array[max] == num ? max : index;
    }
    return index;
}
```

更好的版本

```java
public static int binarySearch(int[] array, int num) {
    int min = 0;
    int max = array.length - 1;
    int mid = (max + min) / 2;
    
    while (array[mid] != num) {
        if (num > array[mid]) {
            min = mid + 1;
        } else if (num < array[mid]) {
            max = mid - 1;
        }
        if (min > max) {
            return -1;
        }
        mid = (max + min) / 2;
    }
    return mid;
}
```

> 编写顺序查找的方法`public static int[] ordinalSearch(int data[],int key)`，要求该方法返回一个数组（如果`key`存在，数组中各元素的值分别为关键字`key`在原数组`data`中的各下标；如果`key`不存在，则返回一个长度为`1`的数组，数组元素为`-1`）。
>
> 基本过程思路：
>
> 1. 先扫描数组`data`，统计数组中`key`的个数`n`
>
> 2. 如果`n`为`0`，直接返回一个数组元素为`－1`的数组；否则的话定义一个数组`int index[]=new int[n]`，再扫描数组`data`，把数组中值为`key`的各个元素的下标保存到数组`index`中，最后返回数组`index`

## foreach循环

 语法

```java
for (元素类型 元素变量 : 遍历对象) {
    使用元素变量的循环体
}
```

遍历输出数组元素

```java
for (int i : array) {
    System.out.println(i);
}
```

## Arrays工具类

`import java.util.Arrays`

```java
import java.util.Arrays;
public class ArrayDemo06 {
/**
* Arrays工具类介绍
*
* @param args
*/
    public static void main(String[] args) {
    int[] a = {11,7,22,33,99,225,44,66,55,66,87,7};
    int[] b = {11,7,22,33,99,225,44,66,55,66,87,7};
    // 将数组转换为一个字符串
    System.out.println(Arrays.toString(a));
    // 排序
    // Arrays.sort(a);
    // 指定某个范围内的数据排序
    //Arrays.sort(a, 3, 8);
    System.out.println(Arrays.toString(a));
    // 二分查找
    int index = Arrays.binarySearch(a, 661);
    System.out.println(index);
    // 判断两个数组是否相等
    System.out.println(Arrays.equals(a, b));
    // 给数组中的元素填充内容
    // Arrays.fill(a, 1);
    // 局部填充
    Arrays.fill(a, 2, 5, 1);
    System.out.println(Arrays.toString(a));
    // 复制数组
    int[] c = Arrays.copyOf(a, a.length-2);
    System.out.println(Arrays.toString(c));
    // 指定范围复制
    int d[] = Arrays.copyOfRange(a, 3, 7);
    System.out.println(Arrays.toString(d));
    }
}
```



## 二维数组

### 定义语法

```java
//1
int[][] arr = new int[m][n];
//2
int arr[][] = new int[m][n];
//3
int[] arr[] = new int[m][n];
/**
*其中的n是可选的
*/
```

### 内存示意图

```java
int[][] array = new array[3][2];
array[0][0] = 1;
array[0][1] = 2;
array[1][0] = 3;
array[1][1] = 4;
array[2][0] = 5;
array[2][1] = 6;
```

![二维数组内存示意图](img\二维数组内存示意图.png)

### 自由的二维数组

``` java
int[][] array = new int[3][];
array[0] = new int[2];
array[1] = new int[3];
array[2] = new int[4];
```

> _array of address_ 或许是高维数组更为贴切的描述

### 二维数组的遍历

```java
public static void arrayPrintToString(int[][] arr) {
    for (int i = 0; i < arr.length; i++) {
        for (int j = 0; j < arr[i].length; j++) {
            System.out.println(arr[i][j]);
        }
    }
}
//foreach version
public static void arrayPrintToString(int[] ... arr){
    for(int[] x : arr){
        for(int y : x){
            System.out.print(y + "\t");
        }
    	System.out.println();
    }
}
```

# 小算法

## 反转数字

```java
public static int reverseNumber(int num) {
    int numNew = 0;
    while (num > 0) {
        numNew *= 10;
        numNew += num % 10;
        num /= 10;
    }
    return numNew;
}
```

## GCD

>辗转相除法：`gcd(m, n) = gcd(n, m mod n)`当`m mod n`为`0`时，`n`的值就是最大公约数

 ```java
 public static int getGCD(int m, int n) {
     if (m % n == 0) {
         return n;
     }
     return getGCD(n, m % n);
 }
 ```
