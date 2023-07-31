alter table zone drop column `weather`;
alter table zone add column `rain_chance1` int(4) not null default 0;
alter table zone add column `rain_chance2` int(4) not null default 0;
alter table zone add column `rain_chance3` int(4) not null default 0;
alter table zone add column `rain_chance4` int(4) not null default 0;
alter table zone add column `rain_duration1` int(4) not null default 0;
alter table zone add column `rain_duration2` int(4) not null default 0;
alter table zone add column `rain_duration3` int(4) not null default 0;
alter table zone add column `rain_duration4` int(4) not null default 0;
alter table zone add column `snow_chance1` int(4) not null default 0;
alter table zone add column `snow_chance2` int(4) not null default 0;
alter table zone add column `snow_chance3` int(4) not null default 0;
alter table zone add column `snow_chance4` int(4) not null default 0;
alter table zone add column `snow_duration1` int(4) not null default 0;
alter table zone add column `snow_duration2` int(4) not null default 0;
alter table zone add column `snow_duration3` int(4) not null default 0;
alter table zone add column `snow_duration4` int(4) not null default 0;

UPDATE `zone` SET `snow_chance1`=25, `snow_chance2`=20, `snow_chance3`=10, `snow_chance4`=20, `snow_duration1`=10, `snow_duration2`=8, `snow_duration3`=5, `snow_duration4`=10 WHERE  `id`=160;
UPDATE `zone` SET `rain_chance1`=5, `rain_chance2`=5 WHERE  `id`=202;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=306;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=304;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=23;
UPDATE `zone` SET `snow_chance1`=50, `snow_chance2`=25, `snow_chance3`=10, `snow_chance4`=25, `snow_duration1`=24, `snow_duration2`=24, `snow_duration3`=24, `snow_duration4`=24 WHERE  `id`=112;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=303;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=50, `rain_chance4`=25, `rain_duration1`=24, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24 WHERE  `id`=302;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_duration1`=10, `rain_duration2`=10 WHERE  `id`=133;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_duration1`=10, `rain_duration2`=10 WHERE  `id`=132;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_duration1`=10, `rain_duration2`=10 WHERE  `id`=131;
UPDATE `zone` SET `rain_chance1`=5, `rain_chance2`=2 WHERE  `id`=257;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=104;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=5, `rain_chance4`=5, `rain_duration1`=2, `rain_duration2`=3, `rain_duration3`=1, `rain_duration4`=2 WHERE  `id`=439;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=365;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=4;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=204;
UPDATE `zone` SET `rain_chance1`=100, `rain_chance2`=100, `rain_chance3`=100, `rain_chance4`=100, `rain_duration1`=24, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24 WHERE  `id`=224;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=138;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=56;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=31;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=34;
UPDATE `zone` SET `rain_chance1`=100, `rain_chance2`=100, `rain_chance3`=100, `rain_chance4`=100, `rain_duration1`=24, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24 WHERE  `id`=419;
UPDATE `zone` SET `rain_chance1`=15, `rain_chance2`=15, `rain_chance3`=5, `rain_chance4`=5 WHERE  `id`=116;
UPDATE `zone` SET `rain_chance1`=15, `rain_chance2`=15, `rain_chance3`=5, `rain_chance4`=5 WHERE  `id`=115;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=188;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=189;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=410;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=75, `rain_chance3`=75, `rain_chance4`=25, `rain_duration1`=16, `rain_duration2`=12, `rain_duration3`=12, `rain_duration4`=16 WHERE  `id`=276;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1, `snow_duration2`=1, `snow_duration3`=1, `snow_duration4`=1 WHERE  `id`=430;
UPDATE `zone` SET `rain_chance2`=19, `rain_chance3`=14, `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1, `snow_chance1`=20, `snow_chance4`=20, `snow_duration1`=2, `snow_duration4`=1 WHERE  `id`=370;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=194;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=108;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=110;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=51;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=196;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=5, `rain_chance4`=10 WHERE  `id`=316;
UPDATE `zone` SET `rain_chance1`=20, `rain_chance3`=10, `rain_chance4`=20, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=166;
UPDATE `zone` SET `rain_chance1`=20, `rain_chance3`=10, `rain_chance4`=20, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10, `snow_duration1`=12 WHERE  `id`=165;
UPDATE `zone` SET `rain_chance1`=20, `rain_chance2`=20, `rain_chance3`=5, `rain_chance4`=10 WHERE  `id`=225;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=329;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=21;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=10, `rain_chance4`=25, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=99;
UPDATE `zone` SET `rain_chance1`=30, `rain_chance2`=30, `rain_chance3`=20, `rain_chance4`=30, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=255;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=10, `rain_chance4`=25, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=301;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=10, `rain_chance4`=25, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=359;
UPDATE `zone` SET `rain_chance1`=20, `rain_chance2`=20, `rain_chance3`=15, `rain_chance4`=20, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=201;
UPDATE `zone` SET `rain_chance1`=35, `rain_chance2`=45, `rain_chance3`=15, `rain_chance4`=20, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=312;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=75, `rain_chance3`=50, `rain_chance4`=5, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=114;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=10, `rain_chance4`=25, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=263;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=10, `rain_chance4`=25, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=36;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=50, `rain_chance4`=25, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=182;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=10, `rain_chance4`=25, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10, `snow_duration1`=12 WHERE  `id`=142;
UPDATE `zone` SET `rain_chance1`=5, `rain_chance2`=3 WHERE  `id`=361;
UPDATE `zone` SET `rain_chance1`=8, `rain_chance2`=5 WHERE  `id`=259;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=357;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=156;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=149;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=50, `rain_chance4`=25, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10, `snow_chance1`=10, `snow_duration1`=10 WHERE  `id`=406;
UPDATE `zone` SET `rain_chance1`=30, `rain_chance2`=40, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=119;
UPDATE `zone` SET `rain_chance1`=3, `rain_chance2`=3, `rain_chance3`=3, `rain_chance4`=3, `rain_duration1`=24, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24 WHERE  `id`=32;
UPDATE `zone` SET `rain_chance1`=3, `rain_chance2`=3, `rain_chance3`=3, `rain_chance4`=3, `rain_duration1`=24, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24 WHERE  `id`=33;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=50, `rain_chance4`=25, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=374;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=10, `rain_chance4`=25, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10, `snow_duration1`=12 WHERE  `id`=412;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=331;
UPDATE `zone` SET `rain_chance1`=5, `rain_chance2`=5 WHERE  `id`=345;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=10, `rain_chance4`=25, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10, `snow_duration1`=12 WHERE  `id`=30;
UPDATE `zone` SET `rain_chance1`=35, `rain_chance2`=45, `rain_chance3`=15, `rain_chance4`=20, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=107;
UPDATE `zone` SET `rain_chance1`=70, `rain_chance2`=70, `rain_chance3`=70, `rain_chance4`=70, `rain_duration1`=24, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24 WHERE  `id`=46;
UPDATE `zone` SET `rain_duration1`=15, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10, `snow_chance1`=25, `snow_chance2`=15, `snow_chance3`=5, `snow_chance4`=15, `snow_duration1`=24, `snow_duration2`=12, `snow_duration3`=6, `snow_duration4`=12 WHERE  `id`=95;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=190;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=10, `rain_chance4`=25, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10, `snow_duration1`=12 WHERE  `id`=275;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=43;
UPDATE `zone` SET `rain_chance1`=35, `rain_chance2`=45, `rain_chance3`=15, `rain_chance4`=20, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=134;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1, `snow_duration2`=1, `snow_duration3`=1, `snow_duration4`=1 WHERE  `id`=97;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1, `snow_duration2`=1, `snow_duration3`=1, `snow_duration4`=1 WHERE  `id`=258;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=199;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=50, `rain_chance4`=25, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=431;
UPDATE `zone` SET `rain_chance1`=30, `rain_chance2`=40, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=200;
UPDATE `zone` SET `rain_chance4`=25 WHERE  `id`=113;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_chance1`=15, `snow_chance2`=15, `snow_chance3`=15, `snow_chance4`=15, `snow_duration1`=24, `snow_duration2`=6, `snow_duration3`=2, `snow_duration4`=10 WHERE  `id`=48;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_chance1`=50, `snow_chance2`=40, `snow_chance3`=35, `snow_chance4`=40, `snow_duration1`=15, `snow_duration2`=10, `snow_duration3`=4, `snow_duration4`=12 WHERE  `id`=436;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24 WHERE  `id`=243;
UPDATE `zone` SET `rain_chance1`=30, `rain_chance2`=30, `rain_chance3`=30, `rain_chance4`=30, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=428;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10, `snow_chance1`=50, `snow_chance2`=15, `snow_chance3`=15, `snow_chance4`=15, `snow_duration1`=24, `snow_duration2`=6, `snow_duration3`=2, `snow_duration4`=10 WHERE  `id`=102;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10, `snow_chance1`=15, `snow_chance2`=15, `snow_chance3`=15, `snow_chance4`=15, `snow_duration1`=24, `snow_duration2`=6, `snow_duration3`=2, `snow_duration4`=10 WHERE  `id`=174;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=136;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_chance1`=50, `snow_chance2`=15, `snow_chance3`=15, `snow_chance4`=15, `snow_duration1`=24, `snow_duration2`=6, `snow_duration3`=2, `snow_duration4`=10 WHERE  `id`=139;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24 WHERE  `id`=404;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24 WHERE  `id`=405;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=50, `rain_chance4`=25, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=143;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=394;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=416;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24 WHERE  `id`=253;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=252;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10, `snow_duration1`=12 WHERE  `id`=362;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=140;
UPDATE `zone` SET `rain_chance1`=30, `rain_chance2`=30, `rain_chance3`=30, `rain_chance4`=30, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_chance1`=5, `snow_chance2`=5, `snow_chance3`=5, `snow_duration1`=1, `snow_duration2`=1, `snow_duration3`=1 WHERE  `id`=418;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24 WHERE  `id`=333;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=140;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=277;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1, `snow_duration2`=1, `snow_duration3`=1, `snow_duration4`=1 WHERE  `id`=103;
UPDATE `zone` SET `rain_chance1`=2, `rain_chance2`=2, `rain_chance3`=2, `rain_chance4`=2, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=332;
UPDATE `zone` SET `rain_chance1`=5, `rain_chance2`=5, `rain_chance3`=5, `rain_chance4`=5, `rain_duration1`=10, `rain_duration2`=10, `rain_duration3`=10, `rain_duration4`=10 WHERE  `id`=336;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=173;
UPDATE `zone` SET `rain_chance1`=2, `rain_chance2`=8, `rain_chance3`=10, `rain_chance4`=3, `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=141;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10, `snow_chance1`=25, `snow_duration1`=24 WHERE  `id`=389;
UPDATE `zone` SET `rain_duration1`=24, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24 WHERE  `id`=191;
UPDATE `zone` SET `rain_chance1`=25, `rain_chance2`=25, `rain_chance3`=50, `rain_chance4`=25, `rain_duration1`=1, `rain_duration2`=1, `rain_duration3`=1, `rain_duration4`=1 WHERE  `id`=223;
UPDATE `zone` SET `rain_duration1`=1, `rain_duration2`=2, `rain_duration3`=1, `rain_duration4`=1, `snow_duration1`=1 WHERE  `id`=49;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=281;
UPDATE `zone` SET `rain_chance1`=6, `rain_chance2`=6, `rain_chance3`=6, `rain_chance4`=6, `rain_duration1`=12, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=288;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=290;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=170;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=27;
UPDATE `zone` SET `rain_chance2`=100, `rain_chance3`=100, `rain_chance4`=50, `rain_duration2`=24, `rain_duration3`=24, `rain_duration4`=24, `snow_chance1`=100, `snow_chance4`=50, `snow_duration1`=24, `snow_duration4`=24 WHERE  `id`=289;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=285;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=171;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=282;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=283;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=24, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=280;
UPDATE `zone` SET `rain_chance1`=10, `rain_chance2`=10, `rain_chance3`=10, `rain_chance4`=10, `rain_duration1`=12, `rain_duration2`=6, `rain_duration3`=2, `rain_duration4`=10 WHERE  `id`=254;