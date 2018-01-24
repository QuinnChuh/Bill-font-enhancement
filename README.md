# Bill-font-enhancement
this repository is about how to enhance the blue font of bill. 

Environment:
  The project is based on vs2010 platform.My test's openCV version is 4.9.2.

More openCV library can see this url:http://wiki.opencv.org.cn/index.php?title=%E9%A6%96%E9%A1%B5&variant=zh-cn 

The project step:

1.split the blue font using compare the RGB value,and find a suitable condition to split the blue font from the bill.
  And generate a two-value mask to judge the correct of segment.
 
2.filter the mask and use the open-operation to optimize the result of segment.

3.show the final result.
