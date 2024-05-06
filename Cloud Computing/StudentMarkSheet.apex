public class StudentMarks {
    public class Subject {
        public String name;
        public Integer marks;
        
        public Subject(String name, Integer marks) {
            this.name = name;
            this.marks = marks;
        }
    }
    
    public class MarkSheet {
        public String studentName;
        public List<Subject> subjects;
        
        public MarkSheet(String studentName, List<Subject> subjects) {
            this.studentName = studentName;
            this.subjects = subjects;
        }
        
        public Integer getTotalMarks(List<Subject> subjects) {
            Integer totalMarks = 0;
            for (Subject subject : subjects) {
                totalMarks += subject.marks;
            }
            System.debug('Total Marks got are ' + totalMarks);
            return totalMarks;
        }
        
        public void getPercentage(List<Subject> subjects) {
            Integer totalMarks = getTotalMarks(subjects);
            Double percent = (Double.valueOf(totalMarks) / (subjects.size() * 100)) * 100;
            System.debug('Student got ' + percent); 
        }
    }
}

// StudentMarks stud = new StudentMarks();

// List<StudentMarks.Subject> subjects = new List<StudentMarks.Subject>{
//     new StudentMarks.Subject('English', 80),
//     new StudentMarks.Subject('Maths', 90),
//     new StudentMarks.Subject('Science', 90)
// };

// StudentMarks.MarkSheet mark = new StudentMarks.cMarkSheet('Darshan', subjects);

// mark.getTotalMarks(subjects);
// mark.getPercentage(subjects);