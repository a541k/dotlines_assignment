-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 04, 2023 at 11:29 AM
-- Server version: 10.1.36-MariaDB
-- PHP Version: 7.2.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `user_information_database`
--

-- --------------------------------------------------------

--
-- Table structure for table `user_info`
--

CREATE TABLE `user_info` (
  `id` int(11) NOT NULL,
  `first_name` varchar(100) NOT NULL,
  `last_name` varchar(100) NOT NULL,
  `email` varchar(100) NOT NULL,
  `subscription_time` varchar(100) NOT NULL,
  `last_entry_time` varchar(100) NOT NULL,
  `view_time` int(10) UNSIGNED NOT NULL,
  `user_no` int(11) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `user_info`
--

INSERT INTO `user_info` (`id`, `first_name`, `last_name`, `email`, `subscription_time`, `last_entry_time`, `view_time`, `user_no`) VALUES
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 1),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 2),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 3),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 4),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 5),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 6),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 7),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 8),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 9),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 10),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 11),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 12),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 13),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 14),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 15),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 16),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 17),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 18),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 19),
(77, 'ashik', 'mahmud', 'ashik@test.com', '2014-05-28 11:30:10', '2014-05-29 12:30:10', 12, 20);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `user_info`
--
ALTER TABLE `user_info`
  ADD PRIMARY KEY (`user_no`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `user_info`
--
ALTER TABLE `user_info`
  MODIFY `user_no` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
