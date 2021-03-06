<?php
/**
 * @copyright 2013 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Ticket $this->ticket
 */
$issueHeader = new Block('tickets/partials/issueHeader.inc', array('disableButtons'=>true));
$thumbnail   = new Block('media/thumbnail.inc');
echo "
<div class=\"thumbnails\">
	<p><a href=\"{$this->ticket->getURL()}\">Back to case</a></p>
";
foreach ($this->ticket->getIssues() as $issue) {
	$html = '';
	foreach ($issue->getMedia() as $media) {
		if ($media->getMedia_type() == 'image') {
			$thumbnail->media = $media;
			$html.= $thumbnail->render('html', $this->template);
		}
	}
	if ($html) {
		$issueHeader->issue = $issue;
		$header = $issueHeader->render('html', $this->template);
		echo "
		<div class=\"issueInfo\">
			<p>Click on the thumbnail for the full size</p>
			$header
			$html
		</div>
		";
	}
}
echo "
</div>
";