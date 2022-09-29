from self import self


# 哈希表
def CheckPermutation(self, s1: str, s2: str) -> bool:
    hmap = dict()
    for i in s1:
        if i not in hmap:
            hmap[i] = 1
            continue
        hmap[i] += 1

    for i in s2:
        if i not in hmap:
            return False
        hmap[i] -= 1

    for i in hmap.values():
        if i != 0:
            return False

    return True


# 偷鸡做法，排序
def CheckPermutationSort(self, s1: str, s2: str) -> bool:
    return sorted(s1) == sorted(s2)


print(CheckPermutation(self, "asvnpzurz", "urzsapzvn"))
