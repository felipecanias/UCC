CREATE TABLE `students` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `full_name` varchar(255) NOT NULL,
  `personal_data` varchar(255) NOT NULL
);

CREATE TABLE `careers` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `degree` varchar(255) NOT NULL
);

CREATE TABLE `subjects` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `name` varchar(255) NOT NULL
);

CREATE TABLE `career_subjects` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `career_id` int,
  `subject_id` int,
  `year` int NOT NULL,
  `semester` int NOT NULL
);

CREATE TABLE `student_careers` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `student_id` int,
  `career_id` int,
  `enrollment_date` date NOT NULL
);

CREATE TABLE `student_subjects` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `student_id` int,
  `subject_id` int,
  `enrollment_date` date NOT NULL,
  `enrollment_status` varchar(255) NOT NULL,
  `status_date` date NOT NULL
);

CREATE TABLE `partials` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `student_subjects_id` int,
  `partial_number` int NOT NULL,
  `date` date NOT NULL,
  `grade` float NOT NULL
);

CREATE TABLE `exam_periods` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `subject_id` int,
  `career_id` int,
  `date` date NOT NULL
);

CREATE TABLE `exam_enrollments` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `exam_period_id` int,
  `student_id` int,
  `enrollment_date` date NOT NULL,
  `grade` float NOT NULL
);

ALTER TABLE `career_subjects` ADD FOREIGN KEY (`career_id`) REFERENCES `careers` (`id`);

ALTER TABLE `career_subjects` ADD FOREIGN KEY (`subject_id`) REFERENCES `subjects` (`id`);

ALTER TABLE `student_careers` ADD FOREIGN KEY (`student_id`) REFERENCES `students` (`id`);

ALTER TABLE `student_careers` ADD FOREIGN KEY (`career_id`) REFERENCES `careers` (`id`);

ALTER TABLE `student_subjects` ADD FOREIGN KEY (`student_id`) REFERENCES `students` (`id`);

ALTER TABLE `student_subjects` ADD FOREIGN KEY (`subject_id`) REFERENCES `subjects` (`id`);

ALTER TABLE `partials` ADD FOREIGN KEY (`student_subjects_id`) REFERENCES `student_subjects` (`id`);

ALTER TABLE `exam_periods` ADD FOREIGN KEY (`subject_id`) REFERENCES `subjects` (`id`);

ALTER TABLE `exam_periods` ADD FOREIGN KEY (`career_id`) REFERENCES `careers` (`id`);

ALTER TABLE `exam_periods` ADD FOREIGN KEY (`id`) REFERENCES `exam_enrollments` (`exam_period_id`);

ALTER TABLE `exam_enrollments` ADD FOREIGN KEY (`student_id`) REFERENCES `students` (`id`);
