#!/usr/bin/env python3
def get_name_and_drink(origin: str) -> bool:
    try:
        temp_buffer = origin.split("is")
        if temp_buffer[-1].endswith("."):#判断末尾是否为.以提取drink_name
            drink_name = temp_buffer[-1][:-1]
        else:
            return False
        try: 
            name_buffer = []
            for i in temp_buffer: 
                if "and" in i:#防止出现多个and 使得name 提取出错
                    name_buffer.append( i.split("and")[0] )
            print(f"your name is one of {name_buffer} and your favorite drink is {drink_name}")
            return True
        except:
            return False
    except:
        return False


def main(args=None):#主入口，如果返回False则持续至输入成功或输入exit退出
    origin_str = input("""
please input your name and your favorite drink
example:my name is li hua and my favorite drink is orange juice.
                    """)#原始输入
    while not get_name_and_drink(origin_str):
        print("请按example中的案例输入或输入exit退出")
        origin_str = input("""
please input your name and your favorite drink
example:my name is li hua and my favorite drink is orange juice.
        """)
        if origin_str == "exit":
            break
if __name__ == '__main__':
    main()
