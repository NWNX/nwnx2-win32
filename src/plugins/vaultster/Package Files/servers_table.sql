/* Table structure for table `servers` */

DROP TABLE IF EXISTS `servers`;

CREATE TABLE `servers` (
  `name` varchar(100) NOT NULL default '',
  `address` varchar(100) NOT NULL default '',
  `dmpassword` varchar(100) NOT NULL default '',
  `playerpassword` varchar(100) NOT NULL default '',
  `vaultport` int(11) NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Addresses and passwords of the servers';

/* If the previous line causes an error, remove DEFAULT, or upgrade to MySQL >= 4.1.1. */