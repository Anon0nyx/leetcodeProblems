def foobar(nums: list) -> list:
    n = len(nums)
    ans = [1]*n

    pre = 1
    for i in range(n):
        print("Current pre: " + str(pre))
        ans[i] = pre
        print("Just placed: " + str(ans[i]) + " into our answer array")
        pre *= nums[i]
        print("New pre: " + str(pre))

    post = 1
    for i in range(n-1, -1, -1):
        print("Current post: " + str(post))
        ans[i] *= post
        print("Just placed: " + str(ans[i]) + " Into our answer array")
        post *= nums[i]
        print("New post: " + str(post))

    return ans

print(foobar([1,2,3,4]))
