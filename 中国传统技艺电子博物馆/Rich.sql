-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: localhost    Database: rich
-- ------------------------------------------------------
-- Server version	5.6.38-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `guard_proj`
--

DROP TABLE IF EXISTS `guard_proj`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `guard_proj` (
  `proj_id` int(11) NOT NULL DEFAULT '0',
  `user_tel` char(11) NOT NULL DEFAULT '',
  `addtion` int(11) DEFAULT NULL,
  PRIMARY KEY (`proj_id`,`user_tel`),
  KEY `user_tel` (`user_tel`),
  CONSTRAINT `guard_proj_ibfk_1` FOREIGN KEY (`proj_id`) REFERENCES `project` (`proj_id`),
  CONSTRAINT `guard_proj_ibfk_2` FOREIGN KEY (`user_tel`) REFERENCES `user` (`user_tel`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `guard_proj`
--

LOCK TABLES `guard_proj` WRITE;
/*!40000 ALTER TABLE `guard_proj` DISABLE KEYS */;
/*!40000 ALTER TABLE `guard_proj` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `investe_proj`
--

DROP TABLE IF EXISTS `investe_proj`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `investe_proj` (
  `proj_id` int(11) NOT NULL DEFAULT '0',
  `user_tel` char(11) NOT NULL DEFAULT '',
  `funding` double NOT NULL,
  PRIMARY KEY (`proj_id`,`user_tel`),
  KEY `user_tel` (`user_tel`),
  CONSTRAINT `investe_proj_ibfk_1` FOREIGN KEY (`proj_id`) REFERENCES `project` (`proj_id`),
  CONSTRAINT `investe_proj_ibfk_2` FOREIGN KEY (`user_tel`) REFERENCES `user` (`user_tel`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `investe_proj`
--

LOCK TABLES `investe_proj` WRITE;
/*!40000 ALTER TABLE `investe_proj` DISABLE KEYS */;
INSERT INTO `investe_proj` VALUES (1,'09876543211',25),(1,'12345678901',64),(1,'13671021552',47),(1,'1463859353',53),(1,'57295294',23);
/*!40000 ALTER TABLE `investe_proj` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `project`
--

DROP TABLE IF EXISTS `project`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `project` (
  `proj_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_tel` char(11) NOT NULL,
  `applicant_name` varchar(40) NOT NULL,
  `applicant_IDcard` char(19) DEFAULT NULL,
  `applicant_mail` varchar(30) NOT NULL,
  `appl_date` varchar(20) DEFAULT NULL,
  `proj_class` int(11) DEFAULT NULL,
  `proj_name` varchar(40) NOT NULL,
  `proj_province` int(11) DEFAULT NULL,
  `proj_city` varchar(20) NOT NULL,
  `proj_region` varchar(30) NOT NULL,
  `proj_addr` text NOT NULL,
  `proj_depict` text NOT NULL,
  `proj_condition` int(11) DEFAULT NULL,
  PRIMARY KEY (`proj_id`),
  UNIQUE KEY `applicant_IDcard` (`applicant_IDcard`),
  KEY `user_tel` (`user_tel`),
  CONSTRAINT `project_ibfk_1` FOREIGN KEY (`user_tel`) REFERENCES `user` (`user_tel`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `project`
--

LOCK TABLES `project` WRITE;
/*!40000 ALTER TABLE `project` DISABLE KEYS */;
INSERT INTO `project` VALUES (1,'13611393447','隋小雨','123750022286946817','13611393447@163.com','2019-09-07',1,'脆皮鸭',1,'北京','海淀区','北京邮电大学','汁多味美老幼皆宜',1);
/*!40000 ALTER TABLE `project` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user` (
  `user_tel` char(11) NOT NULL,
  `user_name` varchar(20) NOT NULL,
  `user_psw` varchar(20) NOT NULL,
  PRIMARY KEY (`user_tel`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES ('09876543211','唐可欣','0909'),('12345678901','gvub','vbudbni'),('13611393447','隋小雨','123'),('13671021552','wqm','qqqqq'),('1463859353','byhi','dvyhid'),('57295294','iohbnivni','qqq');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-09-07 20:28:25
