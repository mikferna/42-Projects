<?php

define( 'DB_NAME', 'db1' );

define( 'DB_USER', 'user' );

define( 'DB_PASSWORD', 'password' );

define( 'DB_HOST', 'mariadb' );

define( 'DB_CHARSET', 'utf8' );

define( 'DB_COLLATE', '' );

define( 'WP_ALLOW_REPAIR', true );

define('AUTH_KEY',         'YKbb+hS7(O.DLtV@q-|AY4_cb7FZc$q&doh1/%JYgYuNm9nW`F8=%hcuMSeDJszA');
define('SECURE_AUTH_KEY',  'blNnLxu+m[9h*=~OeQZ[~C>C)P0}7:V51?lzxzZ,mzW|LtU3|abK&qM-!x&nqk+%');
define('LOGGED_IN_KEY',    '+nTj*6U:)L7<l0?gEve$3e|+0[Cv+o?4:>|Hxn,yUNPO;-CMaM*vCv*2DH`ejojc');
define('NONCE_KEY',        'KSJSbCWg`{a|Q/{#x#D}Mj12+;q;)i>-4b^L3h2+TT638L|+!Bw,I>lh4)^#@9T9');
define('AUTH_SALT',        '<dMm=d#D+AG%|vfD?p}W$5Q-x}~PL1T,+gX(wE)gP[E=dXKKMFhF!;KKc_W21-$O');
define('SECURE_AUTH_SALT', 'e+oUg0ZSk@v1dp]!pn]s+|+a36y|/~6l2_3e[okCdTn`e|*(ki+fj|,5NBG|U2Cy');
define('LOGGED_IN_SALT',   '_S^w/`-MiDiRGqvbP$qH(Mr~-~y=ZZEv}y0Iu~x7nTM)WdPfs|gc0X|S6xMWj:g[');
define('NONCE_SALT',       'G EL@H]20}/d=.Ukd}]+*N|[BX:/0~?|$6ZqUGr<jQKfubnNwf1/+uL12rB@5[9.');

define( 'WP_REDIS_HOST', 'redis' );
define( 'WP_REDIS_PORT', 6379 );     


define('WP_CACHE', true);

$table_prefix = 'wp_';

define( 'WP_DEBUG', true );

if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';
?>