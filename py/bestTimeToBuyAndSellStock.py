def findProfit(prices):
    #find max profit by extending range from start {(0,1),(0,2),(0,3),,,,(0,n)}
    biggestProfit=0
    low=prices[0]
    maxProfitRangeFront = [0]
    for i in range(1,len(prices)):
        if prices[i]<low:
            low=prices[i]
        else:
            profit = prices[i]-low
            biggestProfit = profit if profit>biggestProfit else biggestProfit
        maxProfitRangeFront.append(biggestProfit)
    print(maxProfitRangeFront)


    #find max profit by extending range from end {(n,n-1),(n,n-2),(n,n-3),,,,,,,,(n,0)}
    biggestProfit=0
    max=prices[-1]
    maxProfitRangeBack = [0]
    for i in range(len(prices)-2,-1,-1):
        if prices[i]>max:
            max=prices[i]
        else:
            profit = max-prices[i]
            biggestProfit = profit if profit>biggestProfit else biggestProfit
        maxProfitRangeBack.append(biggestProfit)
    print(maxProfitRangeBack[::-1])
    
    biggestProfit=0
    for i in range(len(maxProfitRangeBack)):
        currentProfit = maxProfitRangeFront[i]+maxProfitRangeBack[(-1*(i+1))]
        biggestProfit = (currentProfit) if currentProfit > biggestProfit else biggestProfit
    
    return biggestProfit


def main():
    inp=input()
    x= [int(x) for x in (inp[1:-1].split(","))]
    # print(x)
    print(findProfit(x))

if __name__ == "__main__":
    main()


#   sample input:
#   [3,5,2,7,4,5,2,5,4,5]