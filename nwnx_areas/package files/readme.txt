This plugin depends on the resource manager plugin for loading areas which are not present in the module file or the override directory when the module is loaded.
If you want to add new areas to a running module, drop the 3 area files (area.are, are.gic, area.git) into the "are" subdirectory of your resource manager directory.

nwnx.ini options; add the following lines to your nwnx.ini

[AREAS]
debugLevel=3

;This is the name of the local location variable used when an area is deleted in which a player logged out.
;Upon returning that player will enter the module at this location instead.
;The failsafe location can be set on the area itself or on the module.
;If neither one is set, players will reenter the module at the module's starting location
LocationFailSafe = LocationFailSafe

