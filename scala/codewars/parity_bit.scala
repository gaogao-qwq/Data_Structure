def parityBit(s: String): String =
  s.split("\\s+")
    .map(p =>
      if ((p.foldLeft(0)(_ + _ - '0') - (p.last - '0')) % 2 == p.last - '0') p.dropRight(1)
      else "error"
    )
    .mkString(" ")

@main def parityBitSolution =
  println(parityBit("01011001"))
  println(parityBit("01101110 01100000"))
  println(parityBit("10100011 00111001 11001100"))
  println(parityBit("01011001 01101110 01100000 01010110 10001111 01100011"))
