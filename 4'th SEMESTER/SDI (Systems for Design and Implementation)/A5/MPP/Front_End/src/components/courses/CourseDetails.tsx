import { Card, CardActions, CardContent, IconButton } from "@mui/material";
import { Container } from "@mui/system";
import { useEffect, useState } from "react";
import { Link, useParams } from "react-router-dom";
import { BACKEND_API_URL } from "../../constants";
import { Bodybuilder } from "../../models/Bodybuilder";
import EditIcon from "@mui/icons-material/Edit";
import DeleteForeverIcon from "@mui/icons-material/DeleteForever";
import ArrowBackIcon from "@mui/icons-material/ArrowBack";

export const CourseDetails = () => {
	const { courseId } = useParams();
	const [course, setCourse] = useState<Bodybuilder>();

	useEffect(() => {
		const fetchCourse = async () => {
			const response = await fetch(`${BACKEND_API_URL}/api/BodyBuilders/${courseId}`);
			const course = await response.json();
			setCourse(course);
		};
		fetchCourse();
	}, [courseId]);

	return (
		<Container>
			<Card>
				<CardContent>
					<IconButton component={Link} sx={{ mr: 3 }} to={`/courses`}>
						<ArrowBackIcon />
					</IconButton>{" "}
					<h1>Bodybuilder Details</h1>
					<p>Bd Name: {course?.name}</p>
					<p>Bd age: {course?.age}</p>
					<p>Bd weight: {course?.weight}</p>
					<p>Bd height: {course?.height}</p>
					<p>Bd division: {course?.division}</p>
				</CardContent>
				<CardActions>
					<IconButton component={Link} sx={{ mr: 3 }} to={`/courses/${courseId}/edit`}>
						<EditIcon />
					</IconButton>

					<IconButton component={Link} sx={{ mr: 3 }} to={`/courses/${courseId}/delete`}>
						<DeleteForeverIcon sx={{ color: "red" }} />
					</IconButton>
				</CardActions>
			</Card>
		</Container>
	);
};
