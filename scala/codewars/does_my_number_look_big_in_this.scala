def narcissistic(n: Int): Boolean =
  var digit = n.toString.length
  n.toString.foldLeft(0)((acc, a) => acc + math.pow(a - '0', digit).toInt) == n

@main def narcissisticSolution =
  println(narcissistic(7))
  println(narcissistic(371))
  println(narcissistic(122))
  println(narcissistic(4887))
