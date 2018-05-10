/*
Navicat MySQL Data Transfer

Source Server         : root
Source Server Version : 50720
Source Host           : localhost:3306
Source Database       : video_center

Target Server Type    : MYSQL
Target Server Version : 50720
File Encoding         : 65001

Date: 2018-04-24 06:42:45
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for position
-- ----------------------------
DROP TABLE IF EXISTS `position`;
CREATE TABLE `position` (
  `position_id` int(11) NOT NULL AUTO_INCREMENT,
  `position_name` varchar(255) DEFAULT NULL,
  `last_update` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`position_id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of position
-- ----------------------------
INSERT INTO `position` VALUES ('1', '电子科技大学', '2017-12-28 14:48:04');

-- ----------------------------
-- Table structure for query
-- ----------------------------
DROP TABLE IF EXISTS `query`;
CREATE TABLE `query` (
  `query_id` int(11) NOT NULL AUTO_INCREMENT,
  `pic_id` varchar(255) DEFAULT NULL,
  `pic_path` varchar(255) DEFAULT NULL,
  `begin_time` datetime DEFAULT NULL,
  `end_time` datetime DEFAULT NULL,
  `last_update` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`query_id`)
) ENGINE=InnoDB AUTO_INCREMENT=245 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of query
-- ----------------------------
INSERT INTO `query` VALUES ('1', '123', 'D:/test/test.txt', '2017-11-11 11:11:11', '2017-11-11 11:11:11', '2017-12-27 18:55:24');
INSERT INTO `query` VALUES ('2', '123', 'D:/test/test.txt', '2017-11-11 11:11:11', '2017-11-11 11:11:11', '2017-12-27 19:14:04');
INSERT INTO `query` VALUES ('3', '456', 'D:/test/test.txt', '2017-11-11 11:11:11', '2017-11-11 11:11:11', '2017-12-27 19:15:15');
INSERT INTO `query` VALUES ('4', '456', 'C:/fjdi/fji.f', '2017-11-06 05:04:01', '2017-11-06 05:04:01', '2017-12-27 19:20:39');
INSERT INTO `query` VALUES ('5', '432', 'D:/test/', '2017-11-11 11:11:11', '2017-11-11 11:11:11', '2017-12-29 15:10:51');
INSERT INTO `query` VALUES ('6', '432', 'D:/test/', '2017-11-11 11:11:11', '2017-11-11 11:11:11', '2017-12-29 16:12:51');
INSERT INTO `query` VALUES ('7', '432', 'D:/test/', '2017-11-11 11:11:11', '2017-11-11 11:11:11', '2017-12-29 16:54:04');
INSERT INTO `query` VALUES ('8', '432', 'D:/test/', '2017-11-11 11:11:11', '2017-11-11 11:11:11', '2017-12-29 16:55:43');
INSERT INTO `query` VALUES ('9', '432', 'D:/test/', '2017-11-11 11:11:11', '2017-11-11 11:11:11', '2017-12-29 16:58:36');
INSERT INTO `query` VALUES ('10', '432', 'D:/test/', '2017-11-11 11:11:11', '2017-11-11 11:11:11', '2017-12-29 17:00:55');
INSERT INTO `query` VALUES ('11', '432', 'D:/test/', '2017-11-11 11:11:11', '2017-11-11 11:11:11', '2017-12-29 17:03:55');
INSERT INTO `query` VALUES ('12', '432', 'D:/test/', '2017-11-11 11:11:11', '2017-11-11 11:11:11', '2017-12-29 17:26:12');
INSERT INTO `query` VALUES ('13', '233', 'D:/test/', '2017-11-11 11:11:11', '2017-11-11 11:11:11', '2017-12-29 17:28:35');
INSERT INTO `query` VALUES ('14', '233', 'test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:29:38');
INSERT INTO `query` VALUES ('15', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:33:32');
INSERT INTO `query` VALUES ('16', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:34:25');
INSERT INTO `query` VALUES ('17', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:36:20');
INSERT INTO `query` VALUES ('18', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:37:14');
INSERT INTO `query` VALUES ('19', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:37:40');
INSERT INTO `query` VALUES ('20', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:39:21');
INSERT INTO `query` VALUES ('21', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:40:26');
INSERT INTO `query` VALUES ('22', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:42:29');
INSERT INTO `query` VALUES ('23', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:43:05');
INSERT INTO `query` VALUES ('24', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:44:16');
INSERT INTO `query` VALUES ('25', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:44:58');
INSERT INTO `query` VALUES ('26', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:46:19');
INSERT INTO `query` VALUES ('27', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:48:11');
INSERT INTO `query` VALUES ('28', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:48:53');
INSERT INTO `query` VALUES ('29', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:49:50');
INSERT INTO `query` VALUES ('30', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:50:12');
INSERT INTO `query` VALUES ('31', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:50:31');
INSERT INTO `query` VALUES ('32', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:52:44');
INSERT INTO `query` VALUES ('33', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:53:32');
INSERT INTO `query` VALUES ('34', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:54:52');
INSERT INTO `query` VALUES ('35', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:55:08');
INSERT INTO `query` VALUES ('36', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:55:28');
INSERT INTO `query` VALUES ('37', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:55:57');
INSERT INTO `query` VALUES ('38', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:57:31');
INSERT INTO `query` VALUES ('39', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:57:52');
INSERT INTO `query` VALUES ('40', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:58:44');
INSERT INTO `query` VALUES ('41', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 17:59:05');
INSERT INTO `query` VALUES ('42', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:00:34');
INSERT INTO `query` VALUES ('43', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:00:51');
INSERT INTO `query` VALUES ('44', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:01:34');
INSERT INTO `query` VALUES ('45', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:02:07');
INSERT INTO `query` VALUES ('46', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:02:47');
INSERT INTO `query` VALUES ('47', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:03:15');
INSERT INTO `query` VALUES ('48', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:03:29');
INSERT INTO `query` VALUES ('49', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:04:04');
INSERT INTO `query` VALUES ('50', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:04:26');
INSERT INTO `query` VALUES ('51', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:05:06');
INSERT INTO `query` VALUES ('52', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:08:24');
INSERT INTO `query` VALUES ('53', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:08:38');
INSERT INTO `query` VALUES ('54', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:09:24');
INSERT INTO `query` VALUES ('55', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:09:33');
INSERT INTO `query` VALUES ('56', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:09:45');
INSERT INTO `query` VALUES ('57', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:10:00');
INSERT INTO `query` VALUES ('58', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:11:25');
INSERT INTO `query` VALUES ('59', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:12:07');
INSERT INTO `query` VALUES ('60', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:12:37');
INSERT INTO `query` VALUES ('61', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:13:42');
INSERT INTO `query` VALUES ('62', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:14:46');
INSERT INTO `query` VALUES ('63', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:15:47');
INSERT INTO `query` VALUES ('64', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:16:06');
INSERT INTO `query` VALUES ('65', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:17:32');
INSERT INTO `query` VALUES ('66', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:18:18');
INSERT INTO `query` VALUES ('67', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-29 18:26:56');
INSERT INTO `query` VALUES ('68', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-30 13:21:57');
INSERT INTO `query` VALUES ('69', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-30 13:37:35');
INSERT INTO `query` VALUES ('70', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-30 13:39:10');
INSERT INTO `query` VALUES ('71', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-30 13:42:14');
INSERT INTO `query` VALUES ('72', '233', 'D:	estserverRecv	est.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2017-12-30 14:05:13');
INSERT INTO `query` VALUES ('73', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-02 09:35:02');
INSERT INTO `query` VALUES ('74', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-02 09:39:39');
INSERT INTO `query` VALUES ('75', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-02 09:40:13');
INSERT INTO `query` VALUES ('76', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-04 11:14:02');
INSERT INTO `query` VALUES ('77', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-04 11:20:37');
INSERT INTO `query` VALUES ('78', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 19:43:11');
INSERT INTO `query` VALUES ('79', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 19:44:05');
INSERT INTO `query` VALUES ('80', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 19:45:12');
INSERT INTO `query` VALUES ('81', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 19:46:28');
INSERT INTO `query` VALUES ('82', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 19:46:43');
INSERT INTO `query` VALUES ('83', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 19:47:03');
INSERT INTO `query` VALUES ('84', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 19:49:04');
INSERT INTO `query` VALUES ('85', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 19:49:21');
INSERT INTO `query` VALUES ('86', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 19:52:52');
INSERT INTO `query` VALUES ('87', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 19:53:05');
INSERT INTO `query` VALUES ('88', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 20:03:56');
INSERT INTO `query` VALUES ('89', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 20:04:53');
INSERT INTO `query` VALUES ('90', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 20:04:58');
INSERT INTO `query` VALUES ('91', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 20:05:02');
INSERT INTO `query` VALUES ('92', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 20:05:24');
INSERT INTO `query` VALUES ('93', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-16 20:05:33');
INSERT INTO `query` VALUES ('94', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-17 09:46:50');
INSERT INTO `query` VALUES ('95', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-17 09:52:47');
INSERT INTO `query` VALUES ('96', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-17 10:04:15');
INSERT INTO `query` VALUES ('97', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-17 10:12:17');
INSERT INTO `query` VALUES ('98', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-17 20:18:34');
INSERT INTO `query` VALUES ('99', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-17 20:19:05');
INSERT INTO `query` VALUES ('100', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-17 20:20:14');
INSERT INTO `query` VALUES ('101', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-17 20:21:50');
INSERT INTO `query` VALUES ('102', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-17 20:23:09');
INSERT INTO `query` VALUES ('103', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-17 20:26:09');
INSERT INTO `query` VALUES ('104', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-18 14:43:51');
INSERT INTO `query` VALUES ('105', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-18 15:06:34');
INSERT INTO `query` VALUES ('106', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-18 16:37:20');
INSERT INTO `query` VALUES ('107', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-18 16:37:34');
INSERT INTO `query` VALUES ('108', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-18 16:37:48');
INSERT INTO `query` VALUES ('109', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 14:51:55');
INSERT INTO `query` VALUES ('110', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 15:32:54');
INSERT INTO `query` VALUES ('111', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 15:33:53');
INSERT INTO `query` VALUES ('112', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 15:36:07');
INSERT INTO `query` VALUES ('113', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 15:37:32');
INSERT INTO `query` VALUES ('114', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 15:39:12');
INSERT INTO `query` VALUES ('115', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 15:39:57');
INSERT INTO `query` VALUES ('116', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 15:40:30');
INSERT INTO `query` VALUES ('117', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 15:40:44');
INSERT INTO `query` VALUES ('118', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 15:40:58');
INSERT INTO `query` VALUES ('119', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 15:41:14');
INSERT INTO `query` VALUES ('120', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 15:41:28');
INSERT INTO `query` VALUES ('121', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:25:36');
INSERT INTO `query` VALUES ('122', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:26:09');
INSERT INTO `query` VALUES ('123', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:26:24');
INSERT INTO `query` VALUES ('124', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:26:48');
INSERT INTO `query` VALUES ('125', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:27:06');
INSERT INTO `query` VALUES ('126', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:28:20');
INSERT INTO `query` VALUES ('127', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:28:46');
INSERT INTO `query` VALUES ('128', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:29:52');
INSERT INTO `query` VALUES ('129', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:30:06');
INSERT INTO `query` VALUES ('130', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:30:20');
INSERT INTO `query` VALUES ('131', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:30:34');
INSERT INTO `query` VALUES ('132', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:30:48');
INSERT INTO `query` VALUES ('133', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:38:40');
INSERT INTO `query` VALUES ('134', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:43:18');
INSERT INTO `query` VALUES ('135', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 16:51:31');
INSERT INTO `query` VALUES ('136', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 19:19:00');
INSERT INTO `query` VALUES ('137', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 19:19:43');
INSERT INTO `query` VALUES ('138', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 19:20:04');
INSERT INTO `query` VALUES ('139', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 19:23:54');
INSERT INTO `query` VALUES ('140', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 19:28:05');
INSERT INTO `query` VALUES ('141', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 19:37:46');
INSERT INTO `query` VALUES ('142', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 19:39:26');
INSERT INTO `query` VALUES ('143', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 19:40:31');
INSERT INTO `query` VALUES ('144', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 19:45:32');
INSERT INTO `query` VALUES ('145', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 19:47:18');
INSERT INTO `query` VALUES ('146', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 20:14:44');
INSERT INTO `query` VALUES ('147', '233', 'D:/test/serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 20:16:23');
INSERT INTO `query` VALUES ('148', '233', './serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 20:31:14');
INSERT INTO `query` VALUES ('149', '233', './serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 20:32:38');
INSERT INTO `query` VALUES ('150', '233', './serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-20 20:34:32');
INSERT INTO `query` VALUES ('151', '233', './serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-21 12:56:54');
INSERT INTO `query` VALUES ('152', '233', './serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-22 09:33:58');
INSERT INTO `query` VALUES ('153', '233', './serverRecv/test.txt', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-22 09:34:48');
INSERT INTO `query` VALUES ('154', '233', './serverRecv/0_2018-11-11-01-01-01_2018-12-12-02-02-02_.jpg', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-22 13:39:51');
INSERT INTO `query` VALUES ('155', '233', './serverRecv/0_2018-11-11-01-01-01_2018-12-12-02-02-02_.jpg', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-22 13:40:55');
INSERT INTO `query` VALUES ('156', '233', './serverRecv/0_2018-11-11-01-01-01_2018-12-12-02-02-02_.jpg', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-22 20:00:51');
INSERT INTO `query` VALUES ('157', '233', './serverRecv/0_2018-11-11-01-01-01_2018-12-12-02-02-02_.jpg', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-22 20:05:10');
INSERT INTO `query` VALUES ('158', '1357', './serverRecv/20180123150820.jpg', '2018-01-11 15:08:04', '2018-01-23 15:08:04', '2018-01-23 15:08:30');
INSERT INTO `query` VALUES ('159', '1358', './serverRecv/20180123151200.jpg', '2018-01-17 15:08:04', '2018-01-23 15:08:04', '2018-01-23 15:12:07');
INSERT INTO `query` VALUES ('160', '1359', './serverRecv/20180123151611.jpg', '2018-01-18 15:15:49', '2018-01-23 15:15:49', '2018-01-23 15:16:20');
INSERT INTO `query` VALUES ('161', '233', './serverRecv/1.jpg', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-23 15:32:44');
INSERT INTO `query` VALUES ('162', '233', './serverRecv/1.jpg', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-23 15:36:48');
INSERT INTO `query` VALUES ('163', '233', './serverRecv/1.jpg', '2017-11-11 11:11:11', '2017-12-12 12:12:12', '2018-01-23 15:39:52');
INSERT INTO `query` VALUES ('164', '1361', './serverRecv/20180123154227.jpg', '2018-01-17 15:41:44', '2018-01-23 15:41:44', '2018-01-23 15:42:36');
INSERT INTO `query` VALUES ('165', '1362', './serverRecv/20180123154720.jpg', '2018-01-14 15:46:56', '2018-01-23 15:46:56', '2018-01-23 15:47:30');
INSERT INTO `query` VALUES ('166', '1363', './serverRecv/20180123160320.jpg', '2018-01-17 16:02:54', '2018-01-23 16:02:54', '2018-01-23 16:03:27');
INSERT INTO `query` VALUES ('167', '1364', './serverRecv/20180123160548.jpg', '2018-01-15 16:02:54', '2018-01-23 16:02:54', '2018-01-23 16:05:58');
INSERT INTO `query` VALUES ('168', '1364', './serverRecv/20180123160548.jpg', '2018-01-15 16:02:54', '2018-01-23 16:02:54', '2018-01-23 16:07:59');
INSERT INTO `query` VALUES ('169', '1365', './serverRecv/20180123163112.jpg', '2018-01-18 16:30:54', '2018-01-23 16:30:54', '2018-01-23 16:31:15');
INSERT INTO `query` VALUES ('170', '1365', './serverRecv/20180123163112.jpg', '2018-01-18 16:30:54', '2018-01-23 16:30:54', '2018-01-23 16:32:00');
INSERT INTO `query` VALUES ('171', '1366', './serverRecv/20180123164050.jpg', '2018-01-17 16:40:28', '2018-01-23 16:40:28', '2018-01-23 16:40:58');
INSERT INTO `query` VALUES ('172', '1366', './serverRecv/20180123164050.jpg', '2018-01-17 16:40:28', '2018-01-23 16:40:28', '2018-01-23 16:41:20');
INSERT INTO `query` VALUES ('173', '1367', './serverRecv/20180123164252.jpg', '2018-01-20 16:42:28', '2018-01-23 16:42:28', '2018-01-23 16:42:59');
INSERT INTO `query` VALUES ('174', '1368', './serverRecv/20180123170017.jpg', '2018-01-22 16:59:16', '2018-01-23 16:59:16', '2018-01-23 17:00:23');
INSERT INTO `query` VALUES ('175', '1369', './serverRecv/20180123171124.jpg', '2018-01-21 17:11:02', '2018-01-23 17:11:02', '2018-01-23 17:11:33');
INSERT INTO `query` VALUES ('176', '1370', './serverRecv/20180123180425.jpg', '2018-01-21 18:03:57', '2018-01-23 18:03:57', '2018-01-23 18:04:33');
INSERT INTO `query` VALUES ('177', '1371', './serverRecv/20180123184827.jpg', '2018-01-21 18:47:57', '2018-01-23 18:47:57', '2018-01-23 18:48:35');
INSERT INTO `query` VALUES ('178', '1372', './serverRecv/20180123190856.jpg', '2018-01-23 19:06:46', '2018-01-23 19:06:46', '2018-01-23 19:09:04');
INSERT INTO `query` VALUES ('179', '1373', './serverRecv/20180123191338.jpg', '2018-01-20 19:13:22', '2018-01-23 19:13:22', '2018-01-23 19:13:48');
INSERT INTO `query` VALUES ('180', '1374', './serverRecv/20180123191451.jpg', '2018-01-19 19:14:26', '2018-01-23 19:14:26', '2018-01-23 19:14:58');
INSERT INTO `query` VALUES ('181', '1375', './serverRecv/20180123191558.jpg', '2018-01-18 19:15:28', '2018-01-23 19:15:28', '2018-01-23 19:16:09');
INSERT INTO `query` VALUES ('182', '1376', './serverRecv/20180123191913.jpg', '2018-01-17 19:18:59', '2018-01-23 19:18:59', '2018-01-23 19:19:23');
INSERT INTO `query` VALUES ('183', '1377', './serverRecv/20180123192251.jpg', '2018-01-17 19:22:30', '2018-01-23 19:22:30', '2018-01-23 19:22:59');
INSERT INTO `query` VALUES ('184', '1378', './serverRecv/20180123195710.jpg', '2018-01-18 19:46:13', '2018-01-23 19:46:13', '2018-01-23 19:57:21');
INSERT INTO `query` VALUES ('185', '1393', './serverRecv/20180124201236.jpg', '2018-01-21 20:12:18', '2018-01-24 20:12:18', '2018-01-24 20:12:47');
INSERT INTO `query` VALUES ('186', '1394', './serverRecv/20180124204258.jpg', '2018-01-22 20:42:24', '2018-01-24 20:42:24', '2018-01-24 20:43:09');
INSERT INTO `query` VALUES ('187', '1398', './serverRecv/20180126101504.jpg', '2018-01-23 10:14:42', '2018-01-26 10:14:42', '2018-01-26 10:16:47');
INSERT INTO `query` VALUES ('188', '1399', './serverRecv/20180126101504.jpg', '2018-01-23 10:14:42', '2018-01-26 10:14:42', '2018-01-26 10:18:46');
INSERT INTO `query` VALUES ('189', '1400', './serverRecv/20180126102137.jpg', '2018-01-23 10:21:02', '2018-01-26 10:21:02', '2018-01-26 10:21:47');
INSERT INTO `query` VALUES ('190', '1401', './serverRecv/20180126102338.jpg', '2018-01-23 10:23:18', '2018-01-26 10:23:18', '2018-01-26 10:23:47');
INSERT INTO `query` VALUES ('191', '1402', './serverRecv/20180126102338.jpg', '2018-01-23 10:23:18', '2018-01-26 10:23:18', '2018-01-26 10:24:24');
INSERT INTO `query` VALUES ('192', '1381', './serverRecv/20180126103101.jpg', '2018-01-14 10:30:32', '2018-01-26 10:30:32', '2018-01-26 10:31:11');
INSERT INTO `query` VALUES ('193', '1382', './serverRecv/20180126105211.jpg', '2018-01-21 10:51:00', '2018-01-26 10:51:00', '2018-01-26 10:52:21');
INSERT INTO `query` VALUES ('194', '1382', './serverRecv/20180126105211.jpg', '2018-01-21 10:51:00', '2018-01-26 10:51:00', '2018-01-26 10:52:59');
INSERT INTO `query` VALUES ('195', '1384', './serverRecv/20180126105211.jpg', '2018-01-21 10:51:00', '2018-01-26 10:51:00', '2018-01-26 10:54:55');
INSERT INTO `query` VALUES ('196', '1385', './serverRecv/20180126140521.jpg', '2018-01-16 14:05:00', '2018-01-26 14:05:00', '2018-01-26 14:05:30');
INSERT INTO `query` VALUES ('197', '1386', './serverRecv/20180126160214.jpg', '2018-01-18 16:01:47', '2018-01-26 16:01:47', '2018-01-26 16:02:40');
INSERT INTO `query` VALUES ('198', '1403', './serverRecv/20180317101353.jpg', '2018-03-15 10:10:35', '2018-03-17 10:10:35', '2018-03-17 10:14:20');
INSERT INTO `query` VALUES ('199', '1403', './serverRecv/20180317101744.jpg', '2018-03-13 13:54:58', '2018-03-17 15:54:58', '2018-03-17 15:55:44');
INSERT INTO `query` VALUES ('200', '1410', './serverRecv/20180409192449.jpg', '2018-04-01 19:22:52', '2018-04-09 19:22:52', '2018-04-09 19:27:39');
INSERT INTO `query` VALUES ('201', '1411', './serverRecv/20180409193131.jpg', '2018-04-01 19:22:52', '2018-04-09 19:22:52', '2018-04-09 19:31:41');
INSERT INTO `query` VALUES ('202', '1412', './serverRecv/20180409193528.jpg', '2017-11-10 19:34:41', '2018-04-09 19:34:41', '2018-04-09 19:35:36');
INSERT INTO `query` VALUES ('203', '1413', './serverRecv/20180409193946.jpg', '2017-11-10 19:34:41', '2018-04-09 19:34:41', '2018-04-09 19:39:52');
INSERT INTO `query` VALUES ('204', '1415', './serverRecv/20180409202052.jpg', '2017-02-06 20:08:11', '2018-04-09 20:08:11', '2018-04-09 20:21:09');
INSERT INTO `query` VALUES ('205', '1416', './serverRecv/20180409202912.jpg', '2016-04-09 20:27:23', '2018-04-09 20:27:23', '2018-04-09 20:29:24');
INSERT INTO `query` VALUES ('206', '1416', './serverRecv/20180409202942.jpg', '2016-04-09 20:27:14', '2018-04-09 20:27:14', '2018-04-09 20:30:42');
INSERT INTO `query` VALUES ('207', '1416', './serverRecv/20180409203041.jpg', '2016-04-09 20:27:14', '2018-04-09 20:27:14', '2018-04-09 20:31:00');
INSERT INTO `query` VALUES ('208', '1416', './serverRecv/20180409203059.jpg', '2016-04-09 20:27:14', '2018-04-09 20:27:14', '2018-04-09 20:31:12');
INSERT INTO `query` VALUES ('209', '1416', './serverRecv/20180409203111.jpg', '2016-04-09 20:27:14', '2018-04-09 20:27:14', '2018-04-09 20:31:23');
INSERT INTO `query` VALUES ('210', '1418', './serverRecv/20180409204350.jpg', '2016-04-09 20:42:30', '2018-04-09 20:42:30', '2018-04-09 20:43:59');
INSERT INTO `query` VALUES ('211', '1419', './serverRecv/20180409204755.jpg', '2016-04-09 20:46:51', '2018-04-09 20:46:51', '2018-04-09 20:48:16');
INSERT INTO `query` VALUES ('212', '1420', './serverRecv/20180409205812.jpg', '2010-04-09 20:57:25', '2018-04-09 20:57:25', '2018-04-09 20:58:19');
INSERT INTO `query` VALUES ('213', '1421', './serverRecv/20180409210825.jpg', '2009-04-09 21:07:17', '2018-04-09 21:07:17', '2018-04-09 21:08:35');
INSERT INTO `query` VALUES ('214', '1422', './serverRecv/20180410162908.jpg', '2016-04-10 16:28:14', '2018-04-10 16:28:14', '2018-04-10 16:29:18');
INSERT INTO `query` VALUES ('215', '1423', './serverRecv/20180410163251.jpg', '2018-01-10 16:32:21', '2018-04-10 16:32:21', '2018-04-10 16:32:59');
INSERT INTO `query` VALUES ('216', '1424', './serverRecv/20180410163435.jpg', '2015-04-10 16:34:07', '2018-04-10 16:34:07', '2018-04-10 16:34:43');
INSERT INTO `query` VALUES ('217', '1427', './serverRecv/20180420143318.jpg', '2017-04-20 14:32:24', '2018-04-20 14:32:24', '2018-04-20 14:33:31');
INSERT INTO `query` VALUES ('218', '1427', './serverRecv/20180420143411.jpg', '2017-04-20 14:32:12', '2018-04-20 14:32:12', '2018-04-20 14:34:41');
INSERT INTO `query` VALUES ('219', '1428', './serverRecv/20180420144158.jpg', '2017-04-20 14:40:59', '2018-04-20 14:40:59', '2018-04-20 14:42:14');
INSERT INTO `query` VALUES ('220', '1428', './serverRecv/20180420144231.jpg', '2017-04-20 14:40:45', '2018-04-20 14:40:45', '2018-04-20 14:43:00');
INSERT INTO `query` VALUES ('221', '1429', './serverRecv/20180421151950.jpg', '2017-04-21 15:18:03', '2018-04-21 15:18:03', '2018-04-21 15:20:02');
INSERT INTO `query` VALUES ('222', '1429', './serverRecv/20180421152027.jpg', '2017-04-21 15:17:53', '2018-04-21 15:17:53', '2018-04-21 15:20:52');
INSERT INTO `query` VALUES ('223', '1429', './serverRecv/20180421152051.jpg', '2016-04-21 15:17:53', '2018-04-21 15:17:53', '2018-04-21 15:21:05');
INSERT INTO `query` VALUES ('224', '1429', './serverRecv/20180421152104.jpg', '2016-04-21 15:17:53', '2018-04-21 15:17:53', '2018-04-21 15:21:20');
INSERT INTO `query` VALUES ('225', '1430', './serverRecv/20180421155439.jpg', '2017-04-21 15:53:56', '2018-04-21 15:53:56', '2018-04-21 15:54:45');
INSERT INTO `query` VALUES ('226', '1430', './serverRecv/20180421155439.jpg', '2017-04-21 15:53:56', '2018-04-21 15:53:56', '2018-04-21 15:55:43');
INSERT INTO `query` VALUES ('227', '1430', './serverRecv/20180421155439.jpg', '2017-04-21 15:53:56', '2018-04-21 15:53:56', '2018-04-21 15:56:25');
INSERT INTO `query` VALUES ('228', '1432', './serverRecv/20180421155931.jpg', '2017-04-21 15:58:56', '2018-04-21 15:58:56', '2018-04-21 15:59:38');
INSERT INTO `query` VALUES ('229', '1435', './serverRecv/20180423163846.jpg', '2017-04-23 16:37:37', '2018-04-23 16:37:37', '2018-04-23 16:38:54');
INSERT INTO `query` VALUES ('230', '1435', './serverRecv/20180423163916.jpg', '2017-04-23 16:37:29', '2018-04-23 16:37:29', '2018-04-23 16:39:37');
INSERT INTO `query` VALUES ('231', '1435', './serverRecv/20180423163937.jpg', '2017-04-23 16:37:29', '2018-04-23 16:37:29', '2018-04-23 16:39:46');
INSERT INTO `query` VALUES ('232', '1435', './serverRecv/20180423163946.jpg', '2017-04-23 16:37:29', '2018-04-23 16:37:29', '2018-04-23 16:39:54');
INSERT INTO `query` VALUES ('233', '1436', './serverRecv/20180423164310.jpg', '2017-04-23 16:37:37', '2018-04-23 16:37:37', '2018-04-23 16:43:15');
INSERT INTO `query` VALUES ('234', '1436', './serverRecv/20180423164327.jpg', '2017-04-23 16:37:29', '2018-04-23 16:37:29', '2018-04-23 16:43:49');
INSERT INTO `query` VALUES ('235', '1436', './serverRecv/20180423164349.jpg', '2017-04-23 16:37:29', '2018-04-23 16:37:29', '2018-04-23 16:43:59');
INSERT INTO `query` VALUES ('236', '1435', './serverRecv/20180423182744.jpg', '2017-04-23 18:27:01', '2018-04-23 18:27:01', '2018-04-23 18:28:16');
INSERT INTO `query` VALUES ('237', '1435', './serverRecv/20180423182846.jpg', '2017-04-23 18:26:55', '2018-04-23 18:26:55', '2018-04-23 18:29:48');
INSERT INTO `query` VALUES ('238', '1435', './serverRecv/20180423182948.jpg', '2017-04-23 18:26:55', '2018-04-23 18:26:55', '2018-04-23 18:30:39');
INSERT INTO `query` VALUES ('239', '1436', './serverRecv/20180423201600.jpg', '2017-04-23 20:14:59', '2018-04-23 20:14:59', '2018-04-23 20:16:13');
INSERT INTO `query` VALUES ('240', '1436', './serverRecv/20180423201600.jpg', '2017-04-23 20:14:59', '2018-04-23 20:14:59', '2018-04-23 20:29:54');
INSERT INTO `query` VALUES ('241', '1436', './serverRecv/20180423201600.jpg', '2017-04-23 20:14:59', '2018-04-23 20:14:59', '2018-04-23 20:37:17');
INSERT INTO `query` VALUES ('242', '1437', './serverRecv/20180424112742.jpg', '2017-04-24 11:24:20', '2018-04-24 11:24:20', '2018-04-24 03:27:47');
INSERT INTO `query` VALUES ('243', '1438', './serverRecv/20180424113235.jpg', '2017-04-24 11:24:20', '2018-04-24 11:24:20', '2018-04-24 03:32:39');
INSERT INTO `query` VALUES ('244', '1439', './serverRecv/20180424113537.jpg', '2017-04-24 11:24:20', '2018-04-24 11:24:20', '2018-04-24 03:35:41');

-- ----------------------------
-- Table structure for result
-- ----------------------------
DROP TABLE IF EXISTS `result`;
CREATE TABLE `result` (
  `result_id` int(11) NOT NULL AUTO_INCREMENT,
  `img_id` varchar(255) DEFAULT NULL,
  `img_path` varchar(255) DEFAULT NULL,
  `appear_time` datetime DEFAULT NULL,
  `disappear_time` datetime DEFAULT NULL,
  `last_update` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`result_id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of result
-- ----------------------------
INSERT INTO `result` VALUES ('1', '7865', 'D:/test/picture.jpg', '2017-12-12 12:12:12', '2018-01-01 01:01:01', '2017-12-28 14:53:52');
