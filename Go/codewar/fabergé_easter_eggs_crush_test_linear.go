package main

import (
	"fmt"
	"math/big"
)

var MOD int64 = 998244353

func Height(n, m *big.Int) int64 {
	pre := calcPre(n)
	var res, tmp int64 = 0, 1

	for i := 1; i < int(n.Int64())+1; i++ {
		inner := new(big.Int).Set(m)
		prod := new(big.Int).SetInt64(tmp)
		sum := new(big.Int).SetInt64(res)

		inner.Add(inner, big.NewInt(1))
		inner.Sub(inner, big.NewInt(int64(i)))

		prod.Mul(prod, inner)
		prod.Mul(prod, big.NewInt(pre[i]))
		prod.Mod(prod, big.NewInt(MOD))
		tmp = prod.Int64()

		sum.Add(sum, big.NewInt(tmp))
		sum.Mod(sum, big.NewInt(MOD))
		res = sum.Int64()
	}
	return res
}

func calcPre(n *big.Int) []int64 {
	var res = []int64{0, 1}
	for i := 2; int64(i) < n.Int64()+1; i++ {
		res = append(res, (MOD-MOD/int64(i))*res[MOD%int64(i)]%MOD)
	}
	return res
}

func main() {
	z := big.NewInt(0)
	fmt.Println(Height(big.NewInt(4), big.NewInt(17)))
	fmt.Println(Height(big.NewInt(13), big.NewInt(550)))
	fmt.Println(Height(big.NewInt(3000), z.Exp(big.NewInt(2), big.NewInt(200), nil)))
}
