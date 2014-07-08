<div class="ratio"></div>
<div class="participant" style="background-image: url(<?php print $fields['picture']->content ?>)">
	<div class="content">
		<div class="name"><a href="<?php print $fields['field_website']->content ?>" target="_blank"><?php print $fields['name']->content ?></a></div>
		<div class="labs"><?php if ( !empty($fields['view']) ) { print $fields['view']->content; } ?></div>
	</div>
</div>