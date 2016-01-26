��            )   �      �  �   �  �   z  X   R  �   �  �   5  �  3  �   �  �   �  �   {	  �   !
    �
  �   �  �   �  �   $    �  �   �    �    �  �   �  �   �  �     �   �  �   �  j     �   �  �   q  |   �  �   r  `  p    �  �   �  f   �  �   �  �   �  �  m    �  �   �  �   �   �   �!  
  +"  �   6#  �   $  �   �$    w%  �   �&  .  D'  7  s(  �   �)  m   R*  �   �*  �   d+  f   0,  U   �,  �   �,  �   �-  �   s.  �   /                                                                                                                    	            
          <tt>Ctrl</tt>-click with the Bucket Fill tool to have it use the background color instead of the foreground color. Similarly, <tt>Ctrl</tt>-clicking with the eyedropper tool sets the background color instead of the foreground color. <tt>Ctrl</tt>-clicking on the layer mask's preview in the Layers dialog toggles the effect of the layer mask. <tt>Alt</tt>-clicking on the layer mask's preview in the Layers dialog toggles viewing the mask directly. <tt>Ctrl</tt>-drag with the Rotate tool will constrain the rotation to 15 degree angles. <tt>Shift</tt>-click on the eye icon in the Layers dialog to hide all layers but that one. <tt>Shift</tt>-click again to show all layers. A floating selection must be anchored to a new layer or to the last active layer before doing other operations on the image. Click on the &quot;New Layer&quot; or the &quot;Anchor Layer&quot; button in the Layers dialog, or use the menus to do the same. After you enabled &quot;Dynamic Keyboard Shortcuts&quot; in the Preferences dialog, you can reassign shortcut keys. Do so by bringing up the menu, selecting a menu item, and pressing the desired key combination. If &quot;Save Keyboard Shortcuts&quot; is enabled, the key bindings are saved when you exit GIMP. You should probably disable &quot;Dynamic Keyboard Shortcuts&quot; afterwards, to prevent accidentally assigning/reassigning shortcuts. Click and drag on a ruler to place a guide on an image. All dragged selections will snap to the guides. You can remove guides by dragging them off the image with the Move tool. GIMP supports gzip compression on the fly. Just add <tt>.gz</tt> (or <tt>.bz2</tt>, if you have bzip2 installed) to the filename and your image will be saved compressed. Of course loading compressed images works too. GIMP uses layers to let you organize your image. Think of them as a stack of slides or filters, such that looking through them you see a composite of their contents. If a layer's name in the Layers dialog is displayed in <b>bold</b>, this layer doesn't have an alpha-channel. You can add an alpha-channel using Layer→Transparency→Add Alpha Channel. If some of your scanned photos do not look colorful enough, you can easily improve their tonal range with the &quot;Auto&quot; button in the Levels tool (Colors→Levels). If there are any color casts, you can correct them with the Curves tool (Colors→Curves). If you stroke a path (Edit→Stroke Path), the paint tools can be used with their current settings. You can use the Paintbrush in gradient mode or even the Eraser or the Smudge tool. If your screen is too cluttered, you can press <tt>Tab</tt> in an image window to toggle the visibility of the toolbox and other dialogs. Most plug-ins work on the current layer of the current image. In some cases, you will have to merge all layers (Image→Flatten Image) if you want the plug-in to work on the whole image. Not all effects can be applied to all kinds of images. This is indicated by a grayed-out menu-entry. You may need to change the image mode to RGB (Image→Mode→RGB), add an alpha-channel (Layer→Transparency→Add Alpha Channel) or flatten it (Image→Flatten Image). Pressing and holding the <tt>Shift</tt> key before making a selection allows you to add to the current selection instead of replacing it. Using <tt>Ctrl</tt> before making a selection subtracts from the current one. When you save an image to work on it again later, try using XCF, GIMP's native file format (use the file extension <tt>.xcf</tt>). This preserves the layers and every aspect of your work-in-progress. Once a project is completed, you can save it as JPEG, PNG, GIF, ... You can adjust or move a selection by using <tt>Alt</tt>-drag. If this makes the window move, your window manager uses the <tt>Alt</tt> key already. Most window managers can be configured to ignore the <tt>Alt</tt> key or to use the <tt>Super</tt> key (or "Windows logo") instead. You can create and edit complex selections using the Path tool. The Paths dialog allows you to work on multiple paths and to convert them to selections. You can drag a layer from the Layers dialog and drop it onto the toolbox. This will create a new image containing only that layer. You can drag and drop many things in GIMP. For example, dragging a color from the toolbox or from a color palette and dropping it into an image will fill the current selection with that color. You can draw simple squares or circles using Edit→Stroke Selection. It strokes the edge of your current selection. More complex shapes can be drawn using the Path tool or with Filters→Render→Gfig. You can get context-sensitive help for most of GIMP's features by pressing the F1 key at any time. This also works inside the menus. You can perform many layer operations by right-clicking on the text label of a layer in the Layers dialog. You can save a selection to a channel (Select→Save to Channel) and then modify this channel with any paint tools. Using the buttons in the Channels dialog, you can toggle the visibility of this new channel or convert it to a selection. You can use <tt>Ctrl</tt>-<tt>Tab</tt> to cycle through all layers in an image (if your window manager doesn't trap those keys...). You can use the middle mouse button to pan around the image (or optionally hold <tt>Spacebar</tt> while you move the mouse). You can use the paint tools to change the selection. Click on the &quot;Quick Mask&quot; button at the bottom left of an image window. Change your selection by painting in the image and click on the button again to convert it back to a normal selection. Project-Id-Version: Gimp-tips
Report-Msgid-Bugs-To: 
POT-Creation-Date: 2007-06-07 03:44+0100
PO-Revision-Date: 2009-03-01 13:08+0300
Last-Translator: Mihkel Tõnnov <mihhkel@gmail.com>
Language-Team: Estonian <gnome-et@linux.ee>
Language: et
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
X-Generator: Emacs
 <tt>Ctrl</tt>-klõps värviga täitmise tööriistaga kasutab värvimiseks esiplaani värvi asemel hoopis tagapõhja värvi. Samamoodi töötab värvi valimise tööriist - <tt>Ctrl</tt>-klõps värvi valimise tööriistaga seab esiplaanivärvi asemel uue taustavärvi. <tt>Ctrl</tt>-klõpsamine kihimaski eelvaatel kihtide dialoogis lülitab kihimaski efekti sisse või välja, <tt>Alt</tt>-klõpsamine lülitab maskivaate sisse või välja. <tt>Ctrl</tt>-lohistamine pööramise tööriistaga lubab pöörata ainult 15 kraadiste nurkade kaupa. <tt>Shift</tt>-klõps silma ikoonil kihtide dialoogis peidab kõik ülejäänud kihid. Uuesti <tt>Shift</tt>-klõpsamisel näidatakse taas kõiki kihte. Ujuvalik tuleb enne pildiga edasi toimetamist ankurdada uuele kihile või viimasele aktiivsele kihile. Klõpsa kihtide dialoogis nupul &quot;Uus kiht&quot; või &quot;Ankurda kiht&quot; - või kasuta vastavaid menüükäske. Pärast &quot;dünaamiliste kiirklahvide&quot; lubamist seadistusdialoogis saad kiirklahve ümber määrata. Selleks ava menüü, vali element ja vajuta soovitud klahvikombinatsiooni. Kui &quot;kiirklahvide salvestamine&quot; on lubatud, salvestatakse need GIMP-i sulgemisel. Hiljem võiks &quot;dünaamilised kiirklahvid&quot; vast välja lülitada, et ennetada nende kogemata muutmist. Joonlaualt saad pildile tõmmata abijooni. Kui kasutad hiljem valikutööriista ja oled valikuga jõudnud piisavalt abijoone lähedale, tõmbab abijoon valiku endaga samale joonele. Abijooni saad pildilt eemaldada neid liigutamistööriistaga joonlauale tagasi vedades. GIMP toetab lennult GZIP-pakkimist. Salvestamisel lisa faili nimele <tt>.gz</tt> (või <tt>.bz2</tt>, kui bzip2 on installitud) ja sinu pilt salvestatakse pakitult. Loomulikult toimib ka pakitud piltide avamine. GIMP võimaldab kasutada pildi korraldamiseks kihte. Mõtle neist kui hulgast üksteise taha asetatud slaididest või filtritest, milledest korraga läbi vaadates moodustub tervikpilt. Kui kihi nimi kihtide dialoogis on <b>rasvane</b>, puudub sellel kihil alfakanal. Alfakanali lisamiseks liigu menüüs Kihid→Läbipaistvus→Lisa alfakanal. Kui mõned skaneeritud fotod ei tundu piisavalt värvikad, saad nende värvivahemikku parandada, kasutades tasemete tööriista nuppu &quot;Automaatne&quot; (Värvid→Tasemed...). Võimalikke värvinihkeid saad parandada kurvide tööriistaga (Värvid→Kurvid...). Kui pintseldad vektorjoont (Redigeerimine→Pintselda vektorjoon), saab kasutada värvimise tööriistu nende aktiivsetes seadeis. Võid kasutada pintslit värvisulanduse režiimis või isegi kustukummi ja määrimistööriista. Kui ekraan on liiga segi paisatud, võid pildiaknas <tt>Tab</tt>-klahvi vajutada. See peidab või toob nähtavale tööriistakasti ja teised dialoogid. Enamus pistikutest (pluginatest) töötlevad aktiivse pildi aktiivset kihti. Mõnikord on vaja kõik pildi kihid ühendada (Pilt→Ühenda kõik kihid) kui tahad, et pistik töötleks kogu pilti. Kõikide piltide puhul ei saa kasutada kõiki efekte. Seda näed hallidest menüükirjetest. Võib-olla on vaja muuta värvirežiim RGB-ks (Pilt→Värvirežiim→RGB), lisada alfakanal (Kihid→Läbipaistvus→Lisa alfakanal) või kõik kihid ühendada (Pilt→Ühenda kõik kihid). Valiku märkimise ajal <tt>Shift</tt>i all hoides lisatakse uus valik praegusele, mitte ei asendata seda. Hoides all <tt>Ctrl</tt>-klahvi lahutatakse uue valiku ala praegusest. Kui salvestad pildi, et sellega hiljem edasi töötada, proovi kasutada GIMP-i jaoks loodud XCF-vormingut (kasuta faililaiendit <tt>.xcf</tt>). Sellega säilitad kihid ja iga nüansi poolelioleva pildi juures. Kui projekt on lõpetatud, võib selle salvestada JPEG-, PNG-, GIF- või muusse vormingusse. Valikut saad reguleerida või liigutada kasutades <tt>Alt</tt>-lohistamist. Kui see paneb hoopis akna liikuma, siis järelikult aknahaldur juba kasutab sellist kombinatsiooni. Enamikku aknahaldureist saab seadistada <tt>Alt</tt>-klahvi eirama või selle asemel <tt>Super</tt>- (ehk "Windows'i") klahvi kasutama. Keerulisi valikuid võid luua ja redigeerida vektorjoonte tööriista kasutades. Vektorjoonte dialoog lubab töötada mitme vektorjoonega ja neid valikuks teisendada. Kui vead mõne kihi kihtide dialoogist tööriistakasti, luuakse uus pilt, mis koosneb ainult sellest kihist. Hiirega lohistades saad GIMP-is palju asju teha. Näiteks tõmmates värvi tööriistakastist või värvipaletilt pildile, värvub valitud osa pildist seda värvi. Lihtsaid kastikesi ja ringikesi saab joonistada kasutades Redigeerimine→Pintselda valikujoon. Keerulisemaid kujundeid saab luua vektorjoonte tööriistaga või Filtrid→Genereerimine→Gfig kasutades. Enamiku GIMP-i vahendite kohta saad asjakohast abi, kui vajutad klahvi F1. See töötab ka menüüdes. Paljusid toiminguid kihtidega saad teha paremklõpsates kihtide dialoogis kihi nimel. Valiku saab salvestada kanalisse (Valik→Salvesta kanalisse) ja siis muuta seda kanalit mõne värvimise tööriistaga. Kanalite dialoogi nuppe kasutades saab uue kanali nähtavust muuta või antud kanali valikuks teisendada. Pildi kihtide vahel liikumiseks saad kasutada klahvikombinatsiooni <tt>Ctrl</tt>-<tt>Tab</tt> (juhul, kui sinu aknahaldur seda kombinatsiooni kinni ei püüa...). Kui pilt on suurem kui aken, saad pildi nihutamiseks kasutada hiire keskmist nuppu. Pilti saab nihutada ka hiirt liigutades ja <tt>tühikuklahvi</tt> all hoides. Valiku muutmiseks saad kasutada värvimise tööriistu. Klõpsa &quot;kiirmaski&quot; nupul pildiakna all vasakul nurgas. Muuda oma valikut pilti värvides ja klõpsa nuppu uuesti ning kiirmask teisendatakse tagasi tavaliseks valikuks. 