

def tonemark(word):
        check = [
                ["á", "ắ", "ấ", "é", "ế", "í", "ố", "ớ", "ó", "ứ", "ú", "ý"],
                ["à", "ằ", "ầ", "è", "ề", "ì", "ồ", "ờ", "ò", "ừ", "ù", "ỳ"],
                ["ã", "ẵ", "ẫ", "ẽ", "ễ", "ĩ", "ỗ", "ỡ", "õ", "ữ", "ũ", "ỹ"],
                ["ả", "ẳ", "ẩ", "ẻ", "ể", "ỉ", "ổ", "ở", "ỏ", "ử", "ủ", "ỷ"],
                ["ạ", "ặ", "ậ", "ẹ", "ệ", "ị", "ộ", "ợ", "ọ", "ự", "ụ", "ỵ"]
        ]
        mapping = [
                1, 2, 4, 3, 5 
        ]
        for c in word:
                for i in range(5):
                        for content in check[i]:
                                if c == content: return mapping[i]
        return 0


import sys

ans = ''
for line in sys.stdin:
        arr = line.split(' ')
        for word in arr:
                print(word)
                if len(word) == 0: continue
                ans += str(tonemark(word))
print(ans)
