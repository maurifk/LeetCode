object Solution {
    def numberOfBeams(bank: Array[String]): Int = {
        def countLasers(row: String): Int = row.count(_ != '0')
        def countAndFilterEmpty(rows: Array[String]): Array[Int] = rows.map(countLasers).filter(_ != 0)

        if (countAndFilterEmpty(bank).nonEmpty) {
            countAndFilterEmpty(bank).zip(countAndFilterEmpty(bank).tail).map { case (a, b) => a * b }.sum
        } else {
            0
        }
    }
}
