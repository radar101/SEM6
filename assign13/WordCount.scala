import org.apache.spark.sql.SparkSession

object WordCount {
  def main(args: Array[String]): Unit = {
    // Create a SparkSession
    val spark = SparkSession.builder()
      .appName("WordCount")
      .getOrCreate()

    // Check if the input file path is provided as a command-line argument
    if (args.length != 1) {
      println("Usage: WordCount <input-file>")
      System.exit(1)
    }

    // Read input file
    val inputFile = args(0)
    val lines = spark.read.textFile(inputFile)

    // Split each line into words
    import spark.implicits._
    val words = lines.flatMap(_.split("\\W+"))

    // Count occurrences of each word
    val wordCounts = words.groupBy("value").count().sort("count")

    // Show word counts
    wordCounts.show()

    // Stop the SparkSession
    spark.stop()
  }
}

