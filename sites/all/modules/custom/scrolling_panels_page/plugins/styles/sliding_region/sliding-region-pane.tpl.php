<?php
	$bg_image_path = '';
	if ( !empty( $settings['background_image_file'] ) )
		$bg_image_path = $settings['background_image_file']['style_paths']['large']['path'];

?><div class="pane" style="background-image:url(<?php print $bg_image_path ?>)">
	<div class="inner">
		<?php if (isset($content->title)): ?>
			<h2 class="pane-title"><?php print $content->title; ?></h2>
		<?php endif ?>
		<div class="pane-content">
			<?php print render($content->content); ?>
		</div>
	</div>
</div>