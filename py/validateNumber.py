class NumberValidator:
    plusMinusFlag = 0
    exponentFlag = 0
    decimalFlag = 0
    integerFlag = 0

    charSet = [
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "+",
        "-",
        ".",
        "e",
        "E",
    ]

    def characterValidator(self, pre, curr):
        if curr is "+" or curr is "-":
            if pre is None and self.plusMinusFlag == 0:
                self.plusMinusFlag = 1
                return True
            if pre in ["e", "E"]:
                return True
            return False
        elif curr in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]:
            if pre in self.charSet:
                self.integerFlag = 1
                return True
            return False
        elif curr in ["e", "E"]:
            if (
                self.exponentFlag == 0
                # and pre is not "."
                and (self.decimalFlag == 1 or self.integerFlag == 1)
            ):
                self.exponentFlag = 1
                return True
            return False
        elif curr is ".":
            if (
                self.decimalFlag == 0
                and self.exponentFlag == 0
                and pre not in ["e", "E", "+", "-"]
            ):
                self.decimalFlag = 1
                return True
            return False
        elif curr is None:
            if pre not in ["e", "E", "+", "-"]:
                return True
            return False

    def sanitizeNumber(self, numberString):
        if numberString[0] not in ["+", "-"]:
            return "+" + numberString
        return numberString

    def isNumber(self, s: str) -> bool:
        testNumber = self.sanitizeNumber(s)
        pre = None
        curr = 0
        self.characterValidator(pre, testNumber[curr])
        pre = 0
        curr = 1
        for i in range(1, len(testNumber)):
            if self.characterValidator(testNumber[pre], testNumber[curr]):
                pre = curr
                curr = i + 1
            else:
                break
        else:
            if self.characterValidator(testNumber[pre], None):
                return True
        return False


validator = NumberValidator()
# print(validator.isNumber("-90e3"))
print(validator.isNumber("."))

# plusMinusFlag = 0
# exponentFlag = 0
# decimalFlag = 0
# integerFlag = 0

# charSet = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "-", ".", "e", "E"]


# def characterValidator(pre, curr):
#     global plusMinusFlag
#     global exponentFlag
#     global decimalFlag
#     global integerFlag

#     if curr is "+" or curr is "-":
#         if pre is None and plusMinusFlag == 0:
#             plusMinusFlag = 1
#             return True
#         if pre in ["e", "E"]:
#             return True
#         return False
#     elif curr in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]:
#         if pre in charSet:
#             integerFlag = 1
#             return True
#         return False
#     elif curr in ["e", "E"]:
#         if (
#             exponentFlag == 0
#             and pre is not "."
#             and (decimalFlag == 1 or integerFlag == 1)
#         ):
#             exponentFlag = 1
#             return True
#         return False
#     elif curr is ".":
#         if decimalFlag == 0 and exponentFlag == 0:
#             decimalFlag = 1
#             return True
#         return False
#     elif curr is None:
#         if pre not in ["e", "E", "+", "-"]:
#             return True
#         return False


# def sanitizeNumber(numberString):
#     if numberString[0] not in ["+", "-"]:
#         return "+" + numberString
#     return numberString


# def isNumber(s: str) -> bool:
#     testNumber = sanitizeNumber(s)
#     pre = None
#     curr = 0
#     characterValidator(pre, testNumber[curr])
#     pre = 0
#     curr = 1
#     for i in range(1, len(testNumber)):
#         if characterValidator(testNumber[pre], testNumber[curr]):
#             pre = curr
#             curr = i + 1
#         else:
#             break
#     else:
#         if characterValidator(testNumber[pre], None):
#             return True
#     return False


# # print(isNumber("-90e3"))
# print(isNumber("99e2.5"))
